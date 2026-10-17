#include <stdio.h>
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
