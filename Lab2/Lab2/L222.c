#include <stdio.h>

void L222() {
	int i = 0, n = 1;
	do {
		printf("2^%d = %d\n", i, n);
		i++;
		n *= 2;
	} while (i <= 5);
}