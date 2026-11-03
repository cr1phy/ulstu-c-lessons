#include "functions.h"
#include <stdio.h>

static int fact(int n) {
	if (n == 0 || n == 1) return 1;
	return n * fact(n - 1);
}

void L1011() {
	int n = 5;
	int result = fact(n);
	printf("%d! = %d\n", n, result);
}