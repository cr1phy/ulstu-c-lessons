#include <stdio.h>

void L211() {
	int x, y;
	printf("¬ведите первое число: ");
	scanf_s("%d", &x);
	printf("¬ведите второе число: ");
	scanf_s("%d", &y);

	if (x == y) {
		printf("„исла равны\n");
		return;
	}
	printf("Ѕќльшее число: %d\n", x > y ? x : y);
	printf("ћеньшее число: %d\n", x < y ? x : y);
}