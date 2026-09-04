// Лабораторная работа 1.2.1
// Падение с высоты

#include <stdio.h>
#include <math.h>
#include <Windows.h>

void l121() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	float h = 12.0,          // высота 12 метров
		g = 9.8,             // ускорение свободного падения
		t = sqrt(2 * h / g); // вычисление времени по высоте

	printf("Предмет падает с высоты %f метров\n", h);
	printf("Он коснётся земли через %f секунд\n", t);
}