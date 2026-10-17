#include <stdio.h>

double fuel_consumption(double volume, double mileage) {
	return volume / mileage * 100;
}

void L415() {
	double volume, mileage;
	printf("Введите два числа.\n");
	printf("1. Объём потраченного топлива в ЛИТРАХ\n");
	printf("2. Пробег в КИЛОМЕТРАХ\n");
	scanf_s("%lf%lf", &volume, &mileage);
	printf("Ваш расход топлива: %.2lf (л/км)", fuel_consumption(volume, mileage));
}