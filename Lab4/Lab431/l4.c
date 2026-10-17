#include <stdio.h>
#include "l4.h"

int speeding_fine(int current_speed, int speed_limit) {
	int diff = current_speed - speed_limit;

	if (diff <= 0)
		return 0;
	else if (diff <= 20)
		return 40;
	else if (diff <= 30)
		return 100;
	else
		return 350;
}

void task_speeding_fine() {
	int current_speed;
	printf("Уважаемый, у вас какая скорость была?\n>>> ");
	scanf_s("%d", &current_speed);
	if (current_speed < 0) {
		printf("Вы назад ехали или как?\n");
		return;
	}

	int normal_speed;
	printf("А на знаке сколько было?\n>>> ");
	scanf_s("%d", &normal_speed);
	if (normal_speed < 20) {
		printf("Не может такого быть!\n");
		return;
	}

	int result = speeding_fine(current_speed, normal_speed);
	if (result == 0) {
		printf("У вас нет штрафа.\n");
		return;
	}
	printf("Ваш штраф составляет %d евро\n", result);
}

double fuel_consumption(double volume, double mileage) {
	return volume / mileage * 100;
}

void task_fuel_consumption() {
	double volume, mileage;

	printf("Введите количество потраченного топлива: ");
	scanf_s("%lf", &volume);

	printf("Введите пройденное расстояние: ");
	scanf_s("%lf", &mileage);

	printf("Расход топлива: %.2lf л/100 км\n",
		fuel_consumption(volume, mileage));
}

int income_tax(int annual_income) {
	float tax_rate;
	if (annual_income <= 84120)
		tax_rate = 0.1f;
	else if (annual_income <= 120720)
		tax_rate = 0.14f;
	else if (annual_income <= 228000)
		tax_rate = 0.2f;
	else if (annual_income <= 301200)
		tax_rate = 0.31f;
	else if (annual_income <= 560280)
		tax_rate = 0.35f;
	else if (annual_income <= 721560)
		tax_rate = 0.47f;
	else
		tax_rate = 0.5f;
	return tax_rate * annual_income;
}

void task_income_tax() {
	int annual_income;

	printf("Введите свой годовой доход в шекелях: ");
	scanf_s("%d", &annual_income);

	printf("Вам нужно заплатить: %d шек.\n",
		income_tax(annual_income));
}