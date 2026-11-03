#include "functions.h"
#include <stdio.h>

static void recEGE1(int n) {
	if (n >= 1) {
		printf(" %d", n);
		recEGE1(n - 1);
		recEGE1(n - 1);
	}
}

void L1014() {
	recEGE1(3);
}