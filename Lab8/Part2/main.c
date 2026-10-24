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
		// задачи переключают консоль в UTF-8, поэтому возвращаем 1251 перед каждым меню
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		printf("\n===== ЛР 8.2. fgets: обработка строк текстовых файлов =====\n");
		printf(" 1. Задача 8.2.1 - табуляции -> '%%' (text1.txt -> out1.txt)\n");
		printf(" 2. Задача 8.2.2 - латинские буквы -> большие (text2.txt -> out2.txt)\n");
		printf(" 3. Задача 8.2.3 - '#' перед строками с латиницей (text3.txt -> out3.txt)\n");
		printf(" 4. Задача 8.2.4 - латинские буквы -> '&' (text4.txt -> out4.txt)\n");
		printf(" 5. Задача 8.2.5 - количество ';' в строке (text5.txt -> out5.txt)\n");
		printf(" 0. Выход\n\n");

		int choice = read_choice();
		if (choice == 0)
			break;

		switch (choice) {
		case 1: L821(); break;
		case 2: L822(); break;
		case 3: L823(); break;
		case 4: L824(); break;
		case 5: L825(); break;
		default:
			printf("Нет такого пункта.\n");
		}
	}

	return 0;
}
