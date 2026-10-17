#include <Windows.h>
#include <stdio.h>
#include "input.h"
#include "menu.h"

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (1) {
		printf("\n===== Лекция 7. Символы, строки, указатели =====\n");
		printf(" 1. ЛР 7.1 - работа с символами и строками\n");
		printf(" 2. ЛР 7.2 - работа со строками через указатели\n");
		printf(" 0. Выход\n\n");

		int choice = read_choice();
		if (choice == 0)
			break;

		switch (choice) {
		case 1: menu_L71(); break;
		case 2: menu_L72(); break;
		default:
			printf("Нет такого пункта.\n");
		}
	}

	return 0;
}
