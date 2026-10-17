#include <stdio.h>

#define S(a,h) (0.5f * (a) * (h))

void L421() {
	float a, h;
	printf("Введите два числа:\n");
	printf("1. Сторона треугольника\n");
	printf("2. Высота треугольника\n");
	scanf_s("%f%f", &a, &h);
	printf("Площадь треугольника: %.1f", S(a, h));
}