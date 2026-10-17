#include <stdio.h>

int isLeapYear(int year) {
	if (year % 400 == 0)
		return 1;
	if (year % 100 == 0)
		return 0;
	if (year % 4 == 0)
		return 1;
	return 0;
}

void L411() {
	int start, end;
	printf("Введите 2 целых числа\n");
	printf("1. Начало анализируемого интервала\n");
	printf("2. Конец анализируемого интервала\n");
	scanf_s("%d%d", &start, &end);

	int current = start;
	do {
		if (isLeapYear(current))
			printf("%d\t", current);
		current++;
	} while (current <= end);
}