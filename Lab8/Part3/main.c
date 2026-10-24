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

		printf("\n===== ЛР 8.3. getc: генерация HTML из текста =====\n");
		printf(" 1. Задача 8.3.1 - текст в HTML (in1.txt -> out1.html)\n");
		printf(" 2. Задача 8.3.2 - <b>/<i> для слов, вариант 1 (text2.txt -> text2.html)\n");
		printf(" 0. Выход\n\n");

		int choice = read_choice();
		if (choice == 0)
			break;

		switch (choice) {
		case 1: L831(); break;
		case 2: L832(); break;
		default:
			printf("Нет такого пункта.\n");
		}
	}

	return 0;
}
