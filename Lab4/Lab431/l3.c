#include <stdio.h>
#include "l3.h"

int compound_interest(int amount, int percent, int years) {
	for (int year = 0; year < years; year++) {
		amount += amount * (percent / 100.0f);
	}
	return amount;
}

void task_compound_interest() {
	int amount, percent, years;

	printf("Введите начальную сумму вклада: ");
	scanf_s("%d", &amount);

	printf("Введите процентную ставку: ");
	scanf_s("%d", &percent);

	printf("Введите количество лет: ");
	scanf_s("%d", &years);

	printf("Итоговая сумма вклада: %d\n", compound_interest(amount, percent, years));
}

int factorial(int n) {
	int result = 1;

	for (int i = 1; i <= n; i++) {
		result *= i;
	}

	return result;
}

void task_factorial() {
	int n;

	printf("Введите число: ");
	scanf_s("%d", &n);

	printf("Факториал числа %d: %d\n", n, factorial(n));
}

int fibonacci(int n) {
	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	return fibonacci(n - 1) + fibonacci(n - 2);
}

void task_fibonacci() {
	int n;

	printf("Введите номер числа Фибоначчи: ");
	scanf_s("%d", &n);

	printf("%d число Фибоначчи: %d\n", n, fibonacci(n));
}