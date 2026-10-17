#include <stdio.h>
#include "input.h"
#include "L71.h"

void L711(void) {
	printf("Введите символ: ");
	int ch = getchar();
	if (ch != '\n' && ch != EOF)
		clear_input();

	for (int c = ch; c <= ch + 19; c++) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n");
}

void L712(void) {
	printf("Введите символ: ");
	int ch = getchar();
	if (ch != '\n' && ch != EOF)
		clear_input();

	for (int c = ch; c >= ch - 29; c--) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n");
}
