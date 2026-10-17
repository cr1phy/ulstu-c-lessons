#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "L71.h"

void L713(void) {
	char s[128];
	printf("Введите строку: ");
	fgets(s, _countof(s), stdin);

	printf("Вы ввели строку\n>>> %s", s);

	int count = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		count += (s[i] == ' ');
	}
	printf("Количество пробелов: %d\n", count);
}

void L714(void) {
	char s[128];
	printf("Введите строку: ");
	fgets(s, _countof(s), stdin);

	printf("Вы ввели строку\n>>> %s", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ')
			s[i] = '#';
	}

	printf("Строка после обработки\n>>> %s", s);
}

void L7151(void) {
	char s[128];
	printf("Введите строку: ");
	fgets(s, _countof(s), stdin);

	printf("Вы ввели строку\n>>> %s", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit((unsigned char)s[i]))
			s[i] = '$';
	}

	printf("Строка после обработки\n>>> %s", s);
}

static int isdigit_L7152(int ch) {
	return ch >= '0' && ch <= '9';
}

void L7152(void) {
	char s[128];
	printf("Введите строку: ");
	fgets(s, _countof(s), stdin);

	printf("Вы ввели строку\n>>> %s", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit_L7152(s[i]))
			s[i] = '$';
	}

	printf("Строка после обработки\n>>> %s", s);
}

void L716(void) {
	char s[128];
	printf("Введите строку: ");
	fgets(s, _countof(s), stdin);

	printf("Вы ввели строку\n>>> %s", s);

	for (int i = 0; s[i] != '\0'; i++) {
		s[i] = (char)toupper((unsigned char)s[i]);
	}

	printf("Строка после обработки\n>>> %s", s);
}

void L717(void) {
	char s[128];
	printf("Введите строку: ");
	fgets(s, _countof(s), stdin);

	printf("Вы ввели строку\n>>> %s", s);

	for (int i = 0; s[i] != '\0'; i++) {
		char ch = (char)tolower((unsigned char)s[i]);
		if (ch >= 'a' && ch <= 'z' && ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
			s[i] = '&';
	}

	printf("Строка после обработки\n>>> %s", s);
}
