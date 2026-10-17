#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "L71.h"
#include "input.h"

void L713(void) {
	char s[128];
	printf("Введите строку: ");
	if (!read_line(s, sizeof s)) return;

	printf("Вы ввели строку\n>>> %s\n", s);

	int count = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		count += (s[i] == ' ');
	}
	printf("Количество пробелов: %d\n", count);
}

void L714(void) {
	char s[128];
	printf("Введите строку: ");
	if (!read_line(s, sizeof s)) return;

	printf("Вы ввели строку\n>>> %s\n", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ')
			s[i] = '#';
	}

	printf("Строка после обработки\n>>> %s\n", s);
}

void L7151(void) {
	char s[128];
	printf("Введите строку: ");
	if (!read_line(s, sizeof s)) return;

	printf("Вы ввели строку\n>>> %s\n", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit((unsigned char)s[i]))
			s[i] = '$';
	}

	printf("Строка после обработки\n>>> %s\n", s);
}

static int isdigit_L7152(int ch) {
	return ch >= '0' && ch <= '9';
}

void L7152(void) {
	char s[128];
	printf("Введите строку: ");
	if (!read_line(s, sizeof s)) return;

	printf("Вы ввели строку\n>>> %s\n", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit_L7152(s[i]))
			s[i] = '$';
	}

	printf("Строка после обработки\n>>> %s\n", s);
}

void L716(void) {
	char s[128];
	printf("Введите строку: ");
	if (!read_line(s, sizeof s)) return;

	printf("Вы ввели строку\n>>> %s\n", s);

	for (int i = 0; s[i] != '\0'; i++) {
		s[i] = (char)toupper((unsigned char)s[i]);
	}

	printf("Строка после обработки\n>>> %s\n", s);
}

void L717(void) {
	char s[128];
	printf("Введите строку: ");
	if (!read_line(s, sizeof s)) return;

	printf("Вы ввели строку\n>>> %s\n", s);

	for (int i = 0; s[i] != '\0'; i++) {
		char ch = (char)tolower((unsigned char)s[i]);
		if (ch >= 'a' && ch <= 'z' && ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
			s[i] = '&';
	}

	printf("Строка после обработки\n>>> %s\n", s);
}
