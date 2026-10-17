#include <stdio.h>
#include <math.h>

#define BUFFER_SIZE 2048

// последовательность Люка
int P(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return ceil((pow(1.0 + sqrt(2.0), n) - pow((1.0 - sqrt(2.0)), n)) / (2.0 * sqrt(2.0)));
}

char* _logic_L226(int n) {
	char* buffer = malloc(BUFFER_SIZE * sizeof(char));
	int k = 0;

	int offset = 0;
	do {
		offset += sprintf_s(buffer + offset, BUFFER_SIZE - offset, "%d ", P(k));
		k++;
	} while (k < n);
	buffer[offset - 1] = '\0';

	return buffer;
}

void L226() {
	int n;

	printf("N = ");
	scanf_s("%d", &n);

	printf("%s\n", _logic_L226(n));
}

void _test_L226(int n, char* wanted) {
	char* result = _logic_L226(n);
	if (strcmp(result, wanted) == 0) {
		printf("ok (N = %d): `%s`\n", n, wanted);
		return;
	}
	printf("result is `%s`, but wanted `%s` (N = %d) \n", result, wanted, n);
	free(result);
	exit(-1);
}

void tests_L226() {
	_test_L226(0, "0");
	_test_L226(2, "0 1");
	_test_L226(6, "0 1 2 5 12 29");
	_test_L226(10, "0 1 2 5 12 29 70 169 408 985");
}

// блок-схема
// трассировка