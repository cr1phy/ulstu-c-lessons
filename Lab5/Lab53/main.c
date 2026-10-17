#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// Цвета в консоли (escape-последовательности)
#define C_GREEN "\x1b[32m"
#define C_YELLOW "\x1b[33m"
#define C_RED "\x1b[31m"
#define C_CYAN "\x1b[96m"
#define C_CLEAR "\x1b[0m"

// Настройки игры
#define MAX_SEATS 8       // сколько стоек можно купить максимум
#define START_SEATS 3     // сколько стоек в начале
#define START_MONEY 1000  // капитал кафешки (сотрудника)
#define LEAVE_PENALTY 50  // штраф за ушедшего клиента (N из правил)
#define SEAT_PRICE 300    // цена новой стойки
#define CALM_TURNS 10     // сколько ходов клиент ждёт спокойно
#define DEBT_LIMIT 10     // сколько ходов подряд можно быть в минусе
#define NO_SEAT_PENALTY 250 // клиент не нашёл места

// Еда. У каждой еды свой прибор: бургер — гриль, картошка — фритюр, кофе — кофемашина.
// Поэтому номер еды = номер прибора.
#define FOOD_COUNT 3

const char* food_names[FOOD_COUNT] = { "burger", "fries", "coffee" };
const char food_keys[FOOD_COUNT] = { 'b', 'f', 'c' };   // буква прибора в командах
const int food_price[FOOD_COUNT] = { 150, 80, 100 };    // цена за 1 шт.
const int cook_time[FOOD_COUNT] = { 3, 2, 1 };          // сколько ходов готовится
const int appliance_price[FOOD_COUNT] = { 400, 300, 250 };

// Состояние одной позиции заказа
enum ItemState {
	NONE,     // не заказывал
	WAITING,  // ждёт готовки
	COOKING,  // готовится
	READY,    // готово, лежит на приборе
	CARRIED,  // у игрока в руках
	SERVED    // отдано клиенту
};

const char* state_names[] = { "", "wait", "cooking", "READY", "in hands", "served" };

// Клиент. Заказ хранится по номеру еды: count[0] — сколько бургеров и т.д.
struct Client {
	int here;                  // сидит ли кто-то на этой стойке
	int order_taken;           // принял ли игрок заказ
	int waited;                // сколько ходов прошло с прихода
	int patience;              // терпение 3..10
	int count[FOOD_COUNT];     // сколько штук каждой еды (0 = не заказывал)
	int state[FOOD_COUNT];     // enum ItemState
	int cook_left[FOOD_COUNT]; // осталось готовиться
};

// Состояние игры
struct Client clients[MAX_SEATS];
int seats = START_SEATS;
int money = START_MONEY;
int appliances[FOOD_COUNT] = { 1, 1, 1 };  // сколько приборов каждого типа
int busy[FOOD_COUNT];                      // сколько из них сейчас заняты
int turn = 0;
int debt_turns = 0;
int next_spawn = 0;

// Игрок
char player_at = '1';  // где стоит: '1'..'8' — стойка, 'b' 'f' 'c' — прибор
int hand_client = -1;  // чья еда в руках, -1 = руки пустые
int hand_food = 0;     // какая еда в руках

// напечатать ошибку и вернуть 0 (ход не потрачен)
int fail(const char* text) {
	printf(C_RED "%s" C_CLEAR "\n", text);
	return 0;
}

// номер еды/прибора по букве, или -1
int kitchenIndex(int key) {
	for (int f = 0; f < FOOD_COUNT; f++) {
		if (food_keys[f] == key)
			return f;
	}
	return -1;
}

// номер клиента по символу '1'..'8', или -1, если там никого
int clientIndex(int key) {
	int i = key - '1';
	if (i < 0 || i >= seats || !clients[i].here)
		return -1;
	return i;
}

// стоимость заказа клиента (только неотданное, если only_unserved = 1)
int orderSum(int i, int only_unserved) {
	int sum = 0;
	for (int f = 0; f < FOOD_COUNT; f++) {
		if (clients[i].state[f] == NONE)
			continue;
		if (only_unserved && clients[i].state[f] == SERVED)
			continue;
		sum += food_price[f] * clients[i].count[f];
	}
	return sum;
}

// через сколько ходов придёт следующий клиент: сначала редко, потом часто
int spawnInterval() {
	int k = 10 - turn / 15;
	if (k < 2)
		k = 2;
	return k + rand() % 5;
}

// посадить нового клиента на первую свободную стойку (нет мест = штраф)
void spawnClient() {
	for (int i = 0; i < seats; i++) {
		if (clients[i].here)
			continue;

		struct Client c = { 0 };
		c.here = 1;
		c.patience = 3 + rand() % 8;

		// каждую еду заказывает с шансом 1/2, но хотя бы одну точно
		int any = 0;
		while (!any) {
			for (int f = 0; f < FOOD_COUNT; f++) {
				if (rand() % 2) {
					c.count[f] = 1 + rand() % 3;
					c.state[f] = WAITING;
					any = 1;
				}
			}
		}

		clients[i] = c;
		printf(C_CYAN "New client at stand %d!" C_CLEAR "\n", i + 1);
		return;
	}
	// если мест вообще нет - недовольный гость
	money -= NO_SEAT_PENALTY;
	fail("New client would like to sit, but all seats are busy");
}

// убрать клиента со стойки: освободить приборы и выкинуть его еду из рук
void removeClient(int i) {
	for (int f = 0; f < FOOD_COUNT; f++) {
		if (clients[i].state[f] == COOKING)
			busy[f]--;
	}
	if (hand_client == i)
		hand_client = -1;

	struct Client empty = { 0 };
	clients[i] = empty;
}

// клиент уходит недовольным: штраф N + 15% неотданного
void leaveAngry(int i) {
	int penalty = LEAVE_PENALTY + orderSum(i, 1) * 15 / 100;
	money -= penalty;
	printf(C_RED "Client %d left angry: -%d" C_CLEAR "\n", i + 1, penalty);
	removeClient(i);
}

// M — перейти к стойке или прибору
int doMove(int key) {
	int is_stand = key >= '1' && key < '1' + seats;
	if (!is_stand && kitchenIndex(key) < 0)
		return fail("No such place.");
	if (player_at == key)
		return fail("You are already here.");

	player_at = (char)key;
	return 1;
}

// T — принять заказ (стоя у стойки)
int doTake(int key) {
	int i = clientIndex(key);
	if (i < 0)
		return fail("Nobody is there.");
	if (player_at != key)
		return fail("Go to this stand first.");
	if (clients[i].order_taken)
		return fail("Order is already taken.");

	clients[i].order_taken = 1;
	return 1;
}

// C — начать готовить еду клиента (стоя у прибора)
int doCook(int key) {
	int f = kitchenIndex(player_at);
	int i = clientIndex(key);
	if (f < 0)
		return fail("Go to an appliance first.");
	if (i < 0)
		return fail("Nobody is there.");
	if (!clients[i].order_taken)
		return fail("Take the order first.");
	if (clients[i].state[f] != WAITING)
		return fail("This client needs nothing to cook here.");
	if (busy[f] >= appliances[f])
		return fail("This appliance is busy.");

	clients[i].state[f] = COOKING;
	clients[i].cook_left[f] = cook_time[f];
	busy[f]++;
	return 1;
}

// P — забрать готовую еду клиента (стоя у прибора)
int doPick(int key) {
	int f = kitchenIndex(player_at);
	int i = clientIndex(key);
	if (f < 0)
		return fail("Go to an appliance first.");
	if (i < 0)
		return fail("Nobody is there.");
	if (hand_client >= 0)
		return fail("Your hands are full.");
	if (clients[i].state[f] != READY)
		return fail("Nothing is ready for this client here.");

	clients[i].state[f] = CARRIED;
	hand_client = i;
	hand_food = f;
	return 1;
}

// G — отдать еду из рук (стоя у стойки)
int doGive(int key) {
	int i = clientIndex(key);
	if (i < 0)
		return fail("Nobody is there.");
	if (player_at != key)
		return fail("Go to this stand first.");
	if (hand_client != i)
		return fail("You have nothing for this client.");

	clients[i].state[hand_food] = SERVED;
	hand_client = -1;

	// всё отдано? тогда клиент платит и уходит
	for (int f = 0; f < FOOD_COUNT; f++) {
		if (clients[i].state[f] != NONE && clients[i].state[f] != SERVED)
			return 1;
	}
	int sum = orderSum(i, 0);
	money += sum;
	printf(C_GREEN "Client %d paid %d and left happy!" C_CLEAR "\n", i + 1, sum);
	removeClient(i);
	return 1;
}

// B — купить стойку (s) или прибор (b/f/c)
int doBuy(int key) {
	if (key == 's') {
		if (seats >= MAX_SEATS)
			return fail("No room for more stands.");
		if (money < SEAT_PRICE)
			return fail("Not enough money.");
		seats++;
		money -= SEAT_PRICE;
		return 1;
	}

	int f = kitchenIndex(key);
	if (f < 0)
		return fail("Buy what? Bs = stand, Bb/Bf/Bc = appliance.");
	if (money < appliance_price[f])
		return fail("Not enough money.");
	appliances[f]++;
	money -= appliance_price[f];
	return 1;
}

// K — выгнать клиента (стоя у стойки)
int doKick(int key) {
	int i = clientIndex(key);
	if (i < 0)
		return fail("Nobody is there.");
	if (player_at != key)
		return fail("Go to this stand first.");

	leaveAngry(i);
	return 1;
}

int doCommand(int command, int key) {
	switch (command) {
	// или потрачен ход, или что-то не так
	case 'M': return doMove(key);
	case 'T': return doTake(key);
	case 'C': return doCook(key);
	case 'P': return doPick(key);
	case 'G': return doGive(key);
	case 'B': return doBuy(key);
	case 'K': return doKick(key);
	case 'W': return 1;  // просто ждать
	default:  return fail("Unknown command.");
	}
}

// вернёт 1, если все клиенты ушли разом (мгновенный проигрыш)
int doAutoStep() {
	// 1. готовка идёт сама
	for (int i = 0; i < seats; i++) {
		for (int f = 0; f < FOOD_COUNT; f++) {
			if (clients[i].state[f] != COOKING)
				continue;
			clients[i].cook_left[f]--;
			if (clients[i].cook_left[f] <= 0) {
				clients[i].state[f] = READY;
				busy[f]--;
			}
		}
	}

	// 2. терпение и уходы
	int sitting = 0, left = 0;
	for (int i = 0; i < seats; i++) {
		if (!clients[i].here)
			continue;
		sitting++;
		clients[i].waited++;
		if (clients[i].waited > CALM_TURNS)
			clients[i].patience--;
		if (clients[i].patience <= 0) {
			leaveAngry(i);
			left++;
		}
	}

	// 3. ушли все и сразу при полном зале
	if (left > 0 && left == sitting && sitting == seats)
		return 1;

	// 4. новый клиент
	if (turn >= next_spawn) {
		spawnClient();
		next_spawn = turn + spawnInterval();
	}

	// 5. долг: считаем ходы подряд в минусе
	if (money < 0)
		debt_turns++;
	else
		debt_turns = 0;

	turn++;
	return 0;
}

void printClient(int i) {
	struct Client* c = &clients[i];

	// цвет: зелёный = спокоен, жёлтый = терпит, красный = скоро уйдёт
	const char* color = C_RED;
	if (c->waited < CALM_TURNS)
		color = C_GREEN;
	else if (c->patience > 3)
		color = C_YELLOW;

	printf("  %d: %spatience %d" C_CLEAR, i + 1, color, c->patience);
	if (c->waited < CALM_TURNS)
		printf(" (calm %d)", CALM_TURNS - c->waited);
	printf("  ");

	if (!c->order_taken) {
		printf("order not taken\n");
		return;
	}
	for (int f = 0; f < FOOD_COUNT; f++) {
		if (c->state[f] == NONE)
			continue;
		printf("%s x%d [%s", food_names[f], c->count[f], state_names[c->state[f]]);
		if (c->state[f] == COOKING)
			printf(" %d", c->cook_left[f]);
		printf("]  ");
	}
	printf("\n");
}

// напечатать игровое поле
void printGameField() {
	printf("\n===== turn %d   money %d   debt %d/%d =====\n", turn, money, debt_turns, DEBT_LIMIT);

	// кухня: @ - это игрок, busy/всего
	printf("KITCHEN: ");
	for (int f = 0; f < FOOD_COUNT; f++) {
		char me = (player_at == food_keys[f]) ? '@' : ' ';
		printf("%c[%c] %s %d/%d   ", me, food_keys[f], food_names[f], busy[f], appliances[f]);
	}

	// зал: * = свободно, C = клиент, # = не куплено
	printf("\nHALL:    ");
	for (int i = 0; i < MAX_SEATS; i++) {
		if (i >= seats) {
			printf(" [#]  ");
			continue;
		}
		char me = (player_at == '1' + i) ? '@' : ' ';
		char who = clients[i].here ? 'C' : '*';
		printf("%c[%d]%c ", me, i + 1, who);
	}

	printf("\nHANDS:   ");
	if (hand_client < 0)
		printf("empty\n");
	else
		printf("%s x%d for %d\n", food_names[hand_food], clients[hand_client].count[hand_food], hand_client + 1);

	for (int i = 0; i < seats; i++) {
		if (clients[i].here)
			printClient(i);
	}
}

int main() {
	// Инициализируем цвета в терминале
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(handle_out, &mode);
	SetConsoleMode(handle_out, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	srand(time(NULL));

	printf("Hello to the cafe!\n");
	spawnClient();
	next_spawn = spawnInterval();

	int command, key, ch;
	while (1) {
		printGameField();
		printf("Format Command+Key  Key: 1-8 stand, b/f/c appliance, s seat\n");
		printf("[M]ove [T]ake [C]ook [P]ick [G]ive [B]uy [K]ick [W]ait [E]xit\n>>> ");

		// Получить команду: два символа, остальное до конца строки выкинуть
		command = getchar();
		if (command == EOF || command == 'E')
			break;
		key = '\n';
		if (command != '\n')
			key = getchar();
		ch = key;
		while (ch != '\n' && ch != EOF)
			ch = getchar();

		// Неудачная команда ход не тратит
		if (!doCommand(command, key))
			continue;

		// Ход компьютера и проверка проигрыша
		if (doAutoStep()) {
			printf(C_RED "Everyone left at once. Game over." C_CLEAR "\n");
			break;
		}
		if (debt_turns >= DEBT_LIMIT) {
			printf(C_RED "Too long in debt. Game over." C_CLEAR "\n");
			break;
		}
	}

	printf("Turns survived: %d\nBye!\n", turn);
	return 0;
}