#include <stdio.h>

void L223() {
	int summa, procent;

	printf("summa = ");
	scanf_s("%d", &summa);

	printf("procent = ");
	scanf_s("%d", &procent);

	int N = 0;
	do {
		printf("%d RUB in %dth year\n", summa, N);
		summa += summa * (procent / 100.0f);
		N++;
	} while (N <= 10);
}