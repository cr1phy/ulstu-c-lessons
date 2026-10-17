#include <stdio.h>

void L214() {
	int x, y, z, w, d;
	printf("¬ведите п€ть чисел: ");
	scanf_s("%d%d%d%d%d", &x, &y, &z, &w, &d);

	int max = x;
	if (y > max) {
		max = y;
	}
	if (z > max) {
		max = z;
	}
	if (w > max) {
		max = w;
	}
	if (d > max) {
		max = d;
	}

	printf("max = %d", max);
}