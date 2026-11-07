#include "functions.h"
#include <stdio.h>

void f1(int n) {
	printf("%d ", n);
	if (n <= 1) return;
	f1(n - 2);
}

void f2(int n) {
	if (n > 1) f2(n - 2);
	printf("%d ", n);
}

void f3(int n) {
	printf("%d ", n);
	if (n > 1) {
		f3(n - 2);
		printf("%d ", n);
	}
}

void L1012() {
	int n = 7;
	f1(n);
	printf(" f1 FINISH\n");

	f2(n); 
	printf(" f2 FINISH\n");
	
	f3(n);
	printf(" f3 FINISH\n");
}
