// Лабораторная работа 1.2.3
// Покупаем квартиру

#include <stdio.h>
#include <math.h>
#include <Windows.h>

void l123() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	float m; // площадь желаемой квартиры
	int rub_m; // сколько рублей стоит 1 квадратный метр

	printf("Введите площадь желаемой квартиры: ");
	scanf_s("%f", &m);

	printf("Введите стоимость 1 квадратного метра квартиры в рублях: ");
	scanf_s("%d", &rub_m);

	float price = rub_m * m; // вычисление стоимости квартиры
	printf("Квартира площадью %f m*m по цене %d RUB/(m*m) стоит <%10.1f> RUB\n", m, rub_m, price);
}