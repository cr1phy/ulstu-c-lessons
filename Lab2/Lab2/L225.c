#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char* _logic_L225(int n, int a) {
	char* buffer = malloc(BUFFER_SIZE * sizeof(char));
	int r = 0, count = 0;

	if (n == 0) {
		return "N != 0!";
	}

	int offset = 0;
	do {
		r += a;
		offset += sprintf_s(buffer + offset, BUFFER_SIZE - offset, "%d ", r);
		count++;
	} while (count < n);
	buffer[offset - 1] = '\0';

	return buffer;
}

void L225() {
	int n, a;

	printf("N = ");
	scanf_s("%d", &n);

	printf("A = ");
	scanf_s("%d", &a);

	printf("%s\n", _logic_L225(n, a));
}

void _test_L225(int n, int a, char* wanted) {
	char* result = _logic_L225(n, a);
	if (strcmp(result, wanted) == 0) {
		printf("ok (N = %d, A = %d): `%s`\n", n, a, wanted);
		return;
	}
	printf("result is `%s`, but wanted `%s` (N = %d, A = %d) \n", result, wanted, n, a);
	free(result);
	exit(-1);
}

void tests_L225() {
	_test_L225(0, 1024, "N != 0!");
	_test_L225(2, 2, "2 4");
	_test_L225(6, 4, "4 8 12 16 20 24");
	_test_L225(10, 15, "15 30 45 60 75 90 105 120 135 150");
}