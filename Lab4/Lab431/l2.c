#include <stdio.h>
#include "l2.h"

int max_of_three(int x, int y, int z) {
	int max = x;

	if (y > max)
		max = y;

	if (z > max)
		max = z;

	return max;
}

void task_max_of_three() {
	int x, y, z;

	printf("Введите 3 числа: ");
	scanf_s("%d%d%d", &x, &y, &z);

	printf("Максимальное из трёх чисел: %d\n", max_of_three(x, y, z));
}

int deposit_amount(int amount, int percent, int years) {
	for (int year = 0; year < years; year++) {
		amount += amount * (percent / 100.0f);
	}

	return amount;
}

void task_deposit_amount() {
	int amount, percent, years;

	printf("Введите начальную сумму вклада: ");
	scanf_s("%d", &amount);

	printf("Введите процентную ставку: ");
	scanf_s("%d", &percent);

	printf("Введите количество лет: ");
	scanf_s("%d", &years);

	printf("Сумма вклада через %d лет: %d\n",
		years,
		deposit_amount(amount, percent, years));
}

double depreciated_price(int price, int percent, int years) {
	double cost = price;

	for (int year = 0; year < years; year++) {
		cost *= 1 - percent * 0.01;
	}

	return cost;
}

void task_depreciated_price() {
	int price, percent, years;

	printf("Введите начальную стоимость: ");
	scanf_s("%d", &price);

	printf("Введите процент уменьшения стоимости: ");
	scanf_s("%d", &percent);

	printf("Введите количество лет: ");
	scanf_s("%d", &years);
	printf("Стоимость через %d лет: %.2lf\n",
		years,
		depreciated_price(price, percent, years));
}