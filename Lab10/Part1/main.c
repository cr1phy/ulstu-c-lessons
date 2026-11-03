#include "functions.h"
#include <stdio.h>
#include <Windows.h>

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;

	do {
		printf("\n=== ЛР 10.1 ===\n");
		printf("1. 10.1.1 (факториал)\n");
		printf("2. 10.1.2 (f1, f2, f3)\n");
		printf("4. 10.1.4\n");
		printf("5. 10.1.5\n");
		printf("6. 10.1.6\n");
		printf("7. 10.1.7\n");
		printf("8. 10.1.8 (вариант 2)\n");
		printf("9. 10.1.9 (2 своих алгоритма-рисунка)\n");
		printf("0. выход\n");
		printf("> ");

		if (scanf_s("%d", &choice) != 1) {
			while (getchar() != '\n');  // выкинуть мусор из ввода
			choice = -1;
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
		case 0: printf("Выход\n"); break;
		default: printf("Нет такого пункта\n");
		}
	} while (choice != 0);

	return 0;
}