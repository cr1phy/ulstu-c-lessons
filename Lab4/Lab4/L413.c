#include <stdio.h>

int sumDigits(int number) {
	int s = 0;
	while (number != 0) {
		s += number % 10;
		number /= 10;
	}
	return s;
}

void L413() {
	int start, end;
	printf("Введите два числа:\n");
	printf("1. Начало анализируемого интервала\n");
	printf("2. Конец анализируемого интервала\n");
	scanf_s("%d%d", &start, &end);
	
	int n = start;
	do {
		printf("Сумма цифр (%d) = %d\n", n, sumDigits(n));
		n++;
	} while (n <= end);
}