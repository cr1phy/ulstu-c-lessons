#include <stdio.h>

void L414() {
	int current_speed;
	printf("Уважаемый, у вас какая скорость была?\n>>> ");
	scanf_s("%d", &current_speed);
	if (current_speed < 0) {
		printf("Вы назад ехали или как?\n");
		return;
	}

	int normal_speed;
	printf("А на знаке сколько было?\n>>> ");
	scanf_s("%d", &normal_speed);
	if (normal_speed < 20) {
		printf("Не может такого быть!\n");
	}

	int diff = current_speed - normal_speed;
	if (diff <= 0) {
		printf("У вас нет штрафа, всё ок.\n");
	}
	else if (diff <= 20) {
		printf("Вам штраф в размере € 40.\n");
	}
	else if (diff <= 30) {
		printf("Вам штраф в размере € 100.\n");
	}
	else {
		printf("Вам штраф в размере € 350, и лишать вас прав надо.\n");
	}
}