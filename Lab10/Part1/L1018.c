#include "functions.h"
#include <stdio.h>

static void F4(int n) {
	printf("<");
	if (n > 1) {
		F4(n - 1);	
	}
	printf("%d>", n);
}

void L1018() {
	F4(5);
}