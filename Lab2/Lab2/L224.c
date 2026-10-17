#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

char* _logic_L224(int n) {
	char* buffer = malloc(BUFFER_SIZE * sizeof(char)); // сюда весь результат надо писать
	int r = 0, k = 0;

	if (n == 0) {
		return "N != 0!";
	}
	
	int offset = 0;
	do {
		r += 2;
		offset += sprintf_s(buffer + offset, BUFFER_SIZE - offset, "%d ", r);
		k++;
	} while (k < n);

	buffer[offset - 1] = '\0'; // чтобы в конце пробела не было
	
	return buffer;
} 

void L224() {
	int n;
	printf("N = ");
	scanf_s("%d", &n);
	printf("%s\n", _logic_L224(n));
}

void _test_L224(int n, char* wanted) {
	char* result = _logic_L224(n);
	if (strcmp(result, wanted) == 0) {
		printf("ok (n = %d): `%s`\n", n, wanted);
		return;
	}
	printf("result is `%s`, but wanted `%s` (n = %d) \n", result, wanted, n);
	exit(-1);
}

void tests_L224() {
	_test_L224(0, "N != 0!");
	_test_L224(2, "2 4");
	_test_L224(6, "2 4 6 8 10 12");
	_test_L224(10, "2 4 6 8 10 12 14 16 18 20");
}