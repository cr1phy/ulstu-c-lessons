#include <stdio.h>

int isPrime(int num) {
	int count = 0;
	for (int d = 1; d <= num; d++) {
		if (num % d == 0)
			count++;
	}
	return count == 2;
}

void L412() {
	int start, end;
	printf("Введите 2 целых числа\n");
	printf("1. Начало анализируемого интервала\n");
	printf("2. Конец анализируемого интервала\n");
	scanf_s("%d%d", &start, &end);

	int current = start;
	do {
		if (isPrime(current))
			printf("%d ", current);
		current++;
	} while (current <= end);
}