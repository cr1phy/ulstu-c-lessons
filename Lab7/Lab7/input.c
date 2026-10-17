#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "input.h"

void clear_input(void) {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

int read_choice(void) {
	int choice;
	printf(">>> ");

	int read = scanf_s("%d", &choice);
	if (read == EOF)
		return 0;

	clear_input();
	printf("\n");

	if (read != 1)
		return -1;
	return choice;
}

int read_line(char* buffer, size_t capacity) {
	if (capacity == 0 || capacity > INT_MAX) return 0;
	if (fgets(buffer, (int)capacity, stdin) == NULL) {
		printf("Не удалось прочитать строку.\n");
		return 0;
	}

	size_t length = strcspn(buffer, "\n");
	if (buffer[length] == '\n') {
		buffer[length] = '\0';
		return 1;
	}

	// При заполнении буфера проверяем, не осталась ли часть строки во вводе.
	int ch = getchar();
	if (ch == '\n' || ch == EOF) return 1;
	clear_input();
	printf("Строка слишком длинная (максимум %zu символов).\n", capacity - 1);
	return 0;
}
