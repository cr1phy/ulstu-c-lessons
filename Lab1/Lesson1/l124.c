// Лабораторная работа 1.2.4
// Покупаем квартиру - время

#include <stdio.h>
#include <math.h>
#include <Windows.h>

void l124() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	float m; // площадь желаемой квартиры
	int rub_m; // сколько рублей стоит 1 квадратный метр
	float salary; // размер зарплаты в рублях

	printf("Введите площадь желаемой квартиры: ");
	scanf_s("%f", &m);
	if (m <= 0) {
		printf("<<< каво?");
		return;
	}

	printf("Введите стоимость 1 квадратного метра квартиры в рублях: ");
	scanf_s("%d", &rub_m);
	if (rub_m <= 0) {
		printf("<<< каво?");
		return;
	}

	printf("Введите размер зарплаты в рублях: ");
	scanf_s("%f", &salary);
	if (salary <= 0) {
		printf("<<< каво?");
		return;
	}

	float price = rub_m * m; // вычисление стоимости квартиры
	printf("Квартира площадью %.1f m*m по цене %d RUB/(m*m) стоит <%10.1f> RUB\n", m, rub_m, price);

	double months = price / salary; // X месяцев на квартиру
	printf("При зарплате %.1f RUB вам придётся копить на квартиру %.0f месяцев\n", salary, ceil(2*months)); // `ceil(2*months)` = 50% от накоплений
}