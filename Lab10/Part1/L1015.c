#include "functions.h"
#include <stdio.h>

static void F1(int n) {
	if (n > 2) {
		printf("%d\n", n);
		F1(n - 3);
		F1(n - 4);
	}
}

void L1015(void) {
	F1(10);
}