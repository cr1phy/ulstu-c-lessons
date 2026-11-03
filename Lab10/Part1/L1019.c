#include "functions.h"
#include <stdio.h>

static void Stars(int k) {
	if (k == 0) return;
	printf("* ");
	Stars(k - 1);
}

void Triangle(int n) {
	if (n > 1) {
		Triangle(n - 1);
	}
	Stars(n);
	printf("\n");
}

static void Repeat(const char* s, int k) {
	if (k <= 0) return;
	printf("%s", s);
	Repeat(s, k - 1);
}

static void PyramidRow(int i, int n) {
	if (i > n) return;
	Repeat(" ", n - i);
	Repeat("* ", i);
	printf("\n");
	PyramidRow(i + 1, n);
}

void Pyramid(int n) {
	PyramidRow(1, n);
}

void L1019() {
	int n = 10;
	printf("====== Triangle(%d) ======\n", n);
	Triangle(n);
	printf("\n");
	printf("======= Pyramid(%d) =======\n", n);
	Pyramid(n);
}
