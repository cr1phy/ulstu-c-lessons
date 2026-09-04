// Лабораторная работа 1.2.2
// Падение с высоты [2]

#include <stdio.h>
#include <math.h>
#include <Windows.h>

void l122() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	float h; // высота в метрах
	printf("Введите высоту в метрах: ");
	scanf_s("%f", &h);

	float g = 9.8,           // ускорение свободного падения
		t = sqrt(2 * h / g); // вычисление времени по высоте

	printf("Предмет падает с высоты %f метров\n", h);
	printf("Он коснётся земли через %f секунд\n", t);
}