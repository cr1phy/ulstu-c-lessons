// Лабораторная работа 1.2.6
// Формула из физики

// Период колебаний пружинного маятника
// T = 2 * pi * sqrt(m / k)

#define _USE_MATH_DEFINES 1

#include <stdio.h>
#include <math.h>
#include <Windows.h>

void l126() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	float m; // масса груза
	float k; // коэффициент упругости пружины
	
	printf("Введите массу груза в килограммах: ");
	scanf_s("%f", &m);

	printf("Введите коэффициент упругости пружины: ");
	scanf_s("%f", &k);

	float T = 2 * M_PI * sqrt(m / k); // период в секундах
	printf("Период колебаний пружинного маятника: %f сек", T);
}