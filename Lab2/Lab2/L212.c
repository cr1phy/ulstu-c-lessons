#include <stdio.h>

void L212() {
	int x, y, z;
	printf("¬ведите три числа: ");
	scanf_s("%d%d%d", &x, &y, &z);
	
	int max = x;
	if (y > max) {
		max = y;
	}
	if (z > max) {
		max = z;
	}

	printf("max = %d", max);
}