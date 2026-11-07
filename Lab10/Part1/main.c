#include "functions.h"
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>

static int read_choice(void) {
	int ch;
	int choice;
	int valid;

	printf("> ");
	fflush(stdout);

	do {
		ch = getchar();
	} while (ch != EOF && ch != '\n' && isspace((unsigned char)ch));

	if (ch == EOF) return 0;
	if (ch == '\n') return -1;

	choice = ch - '0';
	valid = ch >= '0' && ch <= '9';

	while ((ch = getchar()) != '\n' && ch != EOF) {
		if (!isspace((unsigned char)ch)) valid = 0;
	}

	return valid ? choice : -1;
}

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (1) {
		printf("\n===== ЛР 10.1. Рекурсия =====\n");
		printf("1. 10.1.1 - факториал\n");
		printf("2. 10.1.2 - порядок вызовов f1, f2, f3\n");
		printf("4. 10.1.4 - двойной рекурсивный вызов\n");
		printf("5. 10.1.5 - рекурсия с уменьшением аргумента\n");
		printf("6. 10.1.6 - рекурсия с увеличением аргумента\n");
		printf("7. 10.1.7 - взаимная рекурсия\n");
		printf("8. 10.1.8 - вложенные скобки (вариант 2)\n");
		printf("9. 10.1.9 - треугольник и пирамида\n");
		printf("0. Выход\n");

		int choice = read_choice();
		if (choice == 0) {
			printf("Выход\n");
			break;
		}

		switch (choice) {
		case 1: L1011(); break;
		case 2: L1012(); break;
		case 4: L1014(); break;
		case 5: L1015(); break;
		case 6: L1016(); break;
		case 7: L1017(); break;
		case 8: L1018(); break;
		case 9: L1019(); break;
		default:
			printf("Нет такого пункта. Введите номер из меню.\n");
			continue;
		}
		printf("\n");
	}

	return 0;
}
