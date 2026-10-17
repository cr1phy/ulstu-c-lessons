#include <stdio.h>
#include <string.h>

#define L217_OOPS "Либо не пишешь, либо случайно обогнал топ-1 на typingtest.now"
#define L217_TOOSLOW "Очень медленно"
#define L217_SLOW "Медленно"
#define L217_NORMAL "Нормально"
#define L217_FAST "Быстро"
#define L217_SOFAST "Очень быстро"
#define L217_BLAZINGLYFAST "Мгновенно"

char* _logic_L217(float wpm) {
	if (wpm < 0.1f || wpm > 416.5f) {
		return L217_OOPS;
	}
	if (wpm < 20) {
		return L217_TOOSLOW;
	}
	if (wpm < 30) {
		return L217_SLOW;
	}
	if (wpm < 50) {
		return L217_NORMAL;
	}
	if (wpm < 100) {
		return L217_FAST;
	}
	if (wpm < 250) {
		return L217_SOFAST;
	}
	return L217_BLAZINGLYFAST;
}

void L217() {
	float wpm;

	printf("Введите количество слов в минуту: ");
	scanf_s("%f", &wpm);

	printf("%s\n", _logic_L217(wpm));
}

void _test_L217(float wpm, char* wanted) {
	char* result = _logic_L217(wpm);
	if (strcmp(result, wanted) == 0) {
		printf("ok (wpm = %.2f): `%s`\n", wpm, wanted);
		return;
	}
	printf("result is `%s`, but wanted `%s` (wpm = %.2f) \n", result, wanted, wpm);
	exit(-1);
}

void tests_L217() {
	_test_L217(5.5f, L217_TOOSLOW);
	_test_L217(25, L217_SLOW);
	_test_L217(42, L217_NORMAL);
	_test_L217(79.34f, L217_FAST);
	_test_L217(125, L217_SOFAST);
	_test_L217(354.2f, L217_BLAZINGLYFAST);
}

// Блок-схема 