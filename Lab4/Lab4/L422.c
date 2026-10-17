#include <stdio.h>

#define FtoC(F) ((F - 32.0f) * 5/9)

void L422() {
	float fahrenheits;
	printf("Введите температуру в Фаренгейтах: ");
	scanf_s("%f", &fahrenheits);
	printf("Температура в Цельсиях: %.2f (гр.C)\n", FtoC(fahrenheits));
}