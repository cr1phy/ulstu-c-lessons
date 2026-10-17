#include <stdio.h>
#include <string.h>

#define L213_OOPS "Неверная температура для измерения"
#define L213_SOCOLD "Холодно"
#define L213_COLD "Прохладно"
#define L213_WARM "Тепло"
#define L213_HOT "Жарко"

char* _logic_L213(int temp) {
	if (temp > -55 && temp < 70) {
		if (temp < 18) {
			return L213_SOCOLD;
		}
		if (temp >= 18 && temp < 22) {
			return L213_COLD;
		}
		if (temp >= 22 && temp < 26) {
			return L213_WARM;
		}
		return L213_HOT;
	}
	return L213_OOPS;
}

void L213() {
	int temp;
	printf("Введите температуру в Цельсиях: ");
	scanf_s("%d", &temp);

	printf("%s\n", _logic_L213(temp));
}

void _test_L213(int temp, char* wanted) {
	char* result = _logic_L213(temp);
	if (strcmp(result, wanted) == 0) {
		printf("ok (temp = %d): `%s`\n", temp, wanted);
		return;
	}
	printf("result is `%s`, but wanted `%s` (temp = %d) \n", result, wanted, temp);
	exit(-1);
}

void tests_L213() {
	_test_L213(10, L213_SOCOLD);
	_test_L213(20, L213_COLD);
	_test_L213(25, L213_WARM);
	_test_L213(30, L213_HOT);
}