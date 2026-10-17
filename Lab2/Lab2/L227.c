#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double _logic_L227(int price, int percent, int years) {
	double cost = price;

	int year = 1;
	do {
		cost *= 1 - percent * 0.01;
		printf("%.2lf ", cost);
		year++;
	} while (year <= years);

	return cost;
}

void L227() {
	int price, percent, years;

	printf("Введите изначальную цену за авто: ");
	scanf_s("%d", &price);

	printf("Введите норму амортизации в процентах: ");
	scanf_s("%d", &percent);

	printf("Введите номер года: ");
	scanf_s("%d", &years);

	printf("\nКонечный ценник через %d год(-a)/лет: %.2lf\n", years, _logic_L227(price, percent, years));
}

void _test_L227(int price, int percent, int years, double wanted) {
	double result = _logic_L227(price, percent, years);
	if (fabs(result - wanted) < 0.01) { // double иногда даёт мусор из-за плавающей точки
		printf("\nok (price = %d, percent = %d, years = %d): `%lf`\n", price, percent, years, wanted);
		return;
	}
	printf("\nresult is `%lf`, but wanted `%lf` (price = %d, percent = %d, years = %d)\n", result, wanted, price, percent, years);
	exit(-1);
}

void tests_L227() {
	_test_L227(1500000, 10, 3, 1093500.00);
	_test_L227(1000000, 10, 1, 900000.00);
	_test_L227(800000, 20, 2, 512000.00);
	_test_L227(2000000, 25, 4, 632812.50);
	_test_L227(500000, 0, 5, 500000.00);
}