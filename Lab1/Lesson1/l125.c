// Лабораторная работа 1.2.5
// Формула из математики

// Площадь правильного треугольника
// S = (a^2 * sqrt(3)) / 4

#include <stdio.h>
#include <math.h>
#include <Windows.h>

void l125() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	float a; // сторона правильного треугольника
	printf("Введите сторону правильного треугольника: ");
	scanf_s("%f", &a);

	float s = (a * a * sqrt(3)) / 4; // площадь
	printf("Площадь правильного треугольника: %f", s);
}