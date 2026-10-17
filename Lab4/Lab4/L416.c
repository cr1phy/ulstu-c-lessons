#include <stdio.h>

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

void L416() {
	int income;

	printf("Введите свой годовой доход в шекелях: ");
	scanf_s("%d", &income);

	printf("Вам нужно заплатить ещё: %d (шек.)", income_tax(income));
}