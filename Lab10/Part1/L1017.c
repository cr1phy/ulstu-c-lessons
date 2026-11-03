#include "functions.h"
#include <stdio.h>

void F3(int n);

static void G3(int n) {
	printf("*");
	if (n > 1)
		F3(n - 3);
}

static void F3(int n) {
	if (n > 0)
		G3(n - 1);
}

void L1017() {
	F3(11);
}