#include <stdio.h>
#include "macro.h"

void macro_task_max_of_three() {
	int x, y, z;
	printf("Введите 3 числа: ");
	scanf_s("%d%d%d", &x, &y, &z);
	int result = -1;
	MAX_OF_THREE(x, y, z, result);
	printf("Максимальное из трёх: %d\n", result);
}

void macro_task_factorial() {
	int n;
	printf("n = ");
	scanf_s("%d", &n);
	int result = -1;
	FACTORIAL(n, result);
	printf("n! = %d\n", result);
}