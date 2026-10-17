#include <stdio.h>

#define BMI(m, h) ((m) / ((h) * (h)))

void L423() {
	float mass, height;
	printf("Введите два числа:\n");
	printf("1. Масса тела в КГ\n");
	printf("2. Рост в сантиметрах\n");
	scanf_s("%f%f", &mass, &height);
	printf("Ваш индекс массы тела: %.2f\n", BMI(mass, height / 100.0f));
}