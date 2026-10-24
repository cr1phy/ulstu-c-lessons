#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include "funcs.h"

// Читает номер пункта меню. При ошибке ввода возвращает -1, при EOF - 0 (выход).
static int read_choice(void) {
	int choice;
	printf(">>> ");
	int read = scanf_s("%d", &choice);
	if (read == EOF)
		return 0;

	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {}

	return read == 1 ? choice : -1;
}

int main(void) {
	while (1) {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		printf("\n===== ЛР 8.1. fscanf/fprintf: числа в текстовых файлах =====\n");
		printf(" 1. Задача 8.1.1 - создать hello.c с информацией об авторе\n");
		printf(" 2. Задача 8.1.2 - максимум из трёх чисел (in2.txt -> out2.txt)\n");
		printf(" 3. Задача 8.1.3 - меню массива с сохранением/загрузкой (mas813.txt)\n");
		printf(" 4. Задача 8.1.4 - обработка массива (in4.txt -> out4.txt)\n");
		printf(" 0. Выход\n\n");

		int choice = read_choice();
		if (choice == 0)
			break;

		switch (choice) {
		case 1: L811(); break;
		case 2: L812(); break;
		case 3: L813(); break;
		case 4: L814(); break;
		default:
			printf("Нет такого пункта.\n");
		}
	}

	return 0;
}
