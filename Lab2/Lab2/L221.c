#include <stdio.h>

void L221() {
	int n;

	printf("n = ");
	scanf_s("%d", &n);
	
	int i = 1;
	do {
		printf("%d ", i);
		i++;
	} while (i <= n);
}

// Трассировка