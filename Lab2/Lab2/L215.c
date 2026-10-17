#include <stdio.h>
#include <string.h>
#include <Windows.h>

// Температура на Сатурне.
// 
// -190..-150 => мороз
// -150..-70 => холодно
// -70..20 => тепло
// 20..+inf => жарко (в ядре около 11.7к гр. по Цельсию)
// остальное => ЛИВ

#define L215_OOPS "что-то не так с измерениями"
#define L215_SNOWY "мороз"
#define L215_COLD "холодно"
#define L215_HOT "тепло"
#define L215_TOOHOT "жарко"

char* _logic_L215(int temp) {
	if (temp >= -190 && temp <= 11700) {
		if (temp < -150) {
			return L215_SNOWY;
		}
		if (temp < -70) {
			return L215_COLD;
		}
		if (temp < 20) {
			return L215_HOT;
		}
		return L215_TOOHOT;
	}
	return L215_OOPS;
}

void L215() {
	int temp;
	printf("Введите температуру в Цельсиях: ");
	scanf_s("%d", &temp);

	printf("%s\n", _logic_L215(temp));
}

void _test_L215(int temp, char* wanted) {
	char* result = _logic_L215(temp);
	if (strcmp(result, wanted) == 0) {
		printf("ok (temp = %d): `%s`\n", temp, wanted);
		return;
	}
	printf("result is `%s`, but wanted `%s` (temp = %d) \n", result, wanted, temp);
	exit(-1);
}

void tests_L215() {
	_test_L215(-200, L215_OOPS);
	_test_L215(-151, L215_SNOWY);
	_test_L215(-150, L215_COLD);
	_test_L215(-71, L215_COLD);
	_test_L215(-70, L215_HOT);
	_test_L215(19, L215_HOT);
	_test_L215(20, L215_TOOHOT);
	_test_L215(11700, L215_TOOHOT);
	_test_L215(11701, L215_OOPS);
}