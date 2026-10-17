#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// Цвета в консоли (escape-последовательности)
#define C_GREEN "\x1b[32m"
#define C_YELLOW "\x1b[33m"
#define C_ORANGE "\x1b[38;5;208m"
#define C_RED "\x1b[31m"
#define C_CYAN "\x1b[96m"
#define C_CLEAR "\x1b[0m"

// Максимальная длина веток
#define MAX_LENGTH 10
// Длина, при которой каждая ветка попадает в "выигрыш"
#define WIN_LENGTH 6
// Максимальная жизненная сила ветки
#define MAX_POWER 10

#define HIGHT_TRUNC 3

// Свойства ветки
struct Line {
	int length; // длина ветви - 0 ..MAX_LENGTH
	int power; // жизненная сила ветви - 0..MAX_POWER
	int is_infected; // заражена ли ветвь?
};

// количество веток
#define NUM_LINES 10

// Ветки
struct Line lines[NUM_LINES] = {
	{5, 8}, // length = 5, power = 8
	{5, 8},
	{5, 8},
	{5, 8},
	{5, 8},
	{5, 8},
	{5, 8},
	{5, 8},
	{5, 8},
	{5, 8}
};

// Доп 3. Цены
#define START_MONEY 40

#define PRICE_TREAT 1
#define PRICE_FEED 2
#define PRICE_STRONG 6

// Цена "аптечки"
#define STRONG_POWER 3

#define CUT_LENGTH 2
#define CUT_POWER 3

// напечатать один элемент ветки
void printElement(int power, int is_infected) {
	const char* color;

	if (is_infected)
		color = C_CYAN;
	else if (power >= 8)
		color = C_GREEN;
	else if (power >= 4)
		color = C_YELLOW;
	else if (power >= 2)
		color = C_ORANGE;
	else
		color = C_RED;

	printf("%s#%s", color, C_CLEAR);
}

// напечатать игровое поле
void printGameField() {
	// напечатать ветки
	int i = 0;
	while (i < NUM_LINES) {

		// напечатать пустоту слева от ветки
		int empty_pos = MAX_LENGTH - lines[i].length;
		int pos = 0;
		while (pos < empty_pos) {
			printf(" ");
			pos++;
		}

		// напечатать левую ветку
		while (pos < MAX_LENGTH) {
			printElement(lines[i].power, lines[i].is_infected);
			pos++;
		}

		// напечатать ствол с номером ветки
		printf("[%d]", i);

		// напечатать правую ветку
		while (pos < MAX_LENGTH + lines[i].length) {
			printElement(lines[i].power, lines[i].is_infected);
			pos++;
		}

		// завершить печать ветки
		printf("\n");

		i++;
	}

	// напечатать ствол дерева
	while (i < NUM_LINES + HIGHT_TRUNC) {
		int pos = 0;
		while (pos < MAX_LENGTH) {
			printf(" ");
			pos++;
		}
		printf("###\n");
		i++;
	}
}

// сделать ход компьютера
void doAutoStep() {
	// ЗАРАЖЁННЫХ всячески убиваем
	for (int k = 0; k < NUM_LINES; k++) {
		if (lines[k].is_infected && lines[k].power > 0)
			lines[k].power--;
	}

	// в 1/3 случаев будет выполняться код под условием
	if (rand() % 3 == 0) {
		// случайно выбираем жертву
		int nline = rand() % 10;
		// ЗАРАЖАЕМ
		lines[nline].is_infected = 1;

		// выбранной жертве уменьшаем уровень жизненной силы
		lines[nline].power -= 2;
		if (lines[nline].power < 0) {
			lines[nline].power = 0;
		}
		printf("event = <D> line = <%d>\n", nline);
	}

	// укорачиваем те ветви, у которых низкая жизненная сила
	int i = 0;
	while (i < NUM_LINES) {
		// БАГ: сначала < 2, потом < 5

		// если у ветки меньше четверти силы
		if (lines[i].power < MAX_POWER / 4) {
			lines[i].length -= 2;
		}
		// если у ветки меньше половины силы 
		else if (lines[i].power < MAX_POWER / 2) {
			lines[i].length--;
		}

		if (lines[i].length < 0) {
			lines[i].length = 0;
		}

		i++;
	}

}

int checkWin() {
	int correct_lines = 0, i = 0;
	while (i < NUM_LINES) {
		correct_lines += (lines[i].length > MAX_LENGTH * WIN_LENGTH * 0.1);
		i++;
	}
	
	if (correct_lines == NUM_LINES)
		return 0;
	return 1;
}

int checkLose() {
	for (int i = 0; i < NUM_LINES; i++) {
		if (lines[i].length == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	printf("Hello!\n");

	// Инцицализируем цвета в терминале
	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(handle_out, &mode);
	SetConsoleMode(handle_out, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	// запускаем генератор случайных чисел
	srand(time(NULL));

	// инициализируем валюту
	int money = START_MONEY;
	int spent = 0;

	// команда и номер ветки
	char command;
	char line;

	do {
		printGameField();
		printf("money = %d  spent = %d\n", money, spent);
		printf("Format Command+Line\t\tCommand: [T]reat(%d)/ [S]trong(%d)/ [F]eed(%d)/ [C]ut(+1)  [E]xit\n", PRICE_TREAT, PRICE_STRONG, PRICE_FEED);

		// Получить команду от пользователя
		command = getchar(); // command
		line = getchar(); // line
		getchar(); // \n
		printf("command = <%c> line = <%c>\n", command, line);

		// Исполнить команду пользователя
		if (line >= '0' && line <= '9') {
			int nline = line - '0';

			switch (command) {
			case 'T': // Лечить
				if (money >= PRICE_TREAT && lines[nline].power < MAX_POWER) {
					lines[nline].power++;
					money -= PRICE_TREAT;
					spent += PRICE_TREAT;
				}
				break;
			case 'F': // Подкармливать
				if (money >= PRICE_FEED && lines[nline].length < MAX_LENGTH) {
					lines[nline].length++;
					money -= PRICE_FEED;
					spent += PRICE_FEED;
				}
				break;
			case 'C': // Доп 1. Отрезание ветки
				if (lines[nline].length <= CUT_LENGTH && lines[nline].power <= CUT_POWER) {
					lines[nline].length = 5;
					lines[nline].power = 8;
					lines[nline].is_infected = 0;
					money++;
				}
				break;
			case 'S': // Доп 3. Сильная "аптечка"
				if (money >= PRICE_STRONG) {
					lines[nline].power = min(MAX_POWER, lines[nline].length + STRONG_POWER);
					lines[nline].is_infected = 0;
					money -= PRICE_STRONG;
					spent += PRICE_STRONG;
					break;
				}
			}
		}

		// Исполнить команду компьютера
		doAutoStep();
		// Доп 2. Проверка на выигрыш или проигрыш
		if (checkWin() == 0) {
			printf("u r the winner.\n");
			break;
		}
		if (checkLose() == 0 || money == 0) {
			printf("u r the L0X\n");
			break;
		}
	} while (command != 'E');

	printf("Bye!\n\n\n");
}