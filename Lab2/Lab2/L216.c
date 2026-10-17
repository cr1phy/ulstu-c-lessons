#include <stdio.h>
#include <string.h>

// Цена бензина АИ-95 (Лукойл)
// Источник: данные Росстата (за 2014-2026)

#define L216_CHEAP "Дёшево"
#define L216_NORMAL "Нормально"
#define L216_EXPENSIVE "Дорого"
#define L216_TOOMUCH "Ужас дорого"
#define L216_OOPS "Очень странный ценник"

char* _logic_L216(float price) {
	if (price < 9.5 || price > 300) {
		return L216_OOPS;
	}
	if (price < 40) {
		return L216_CHEAP;
	}
	if (price < 50) {
		return L216_NORMAL;
	}
	if (price < 70) {
		return L216_EXPENSIVE;
	}
	return L216_TOOMUCH;
}

void L216() {
	float price;
	printf("Введите цену АИ-95: ");
	scanf_s("%f", &price);
	
	printf("%s\n", _logic_L216(price));
}

void _test_L216(float price, char* wanted) {
	char* result = _logic_L216(price);
	if (strcmp(result, wanted) == 0) {
		printf("ok (price = %.2f): `%s`\n", price, wanted);
		return;
	}
	printf("result is `%s`, but wanted `%s` (price = %.2f) \n", result, wanted, price);
	exit(-1);
}

void tests_L216() {
	_test_L216(10, L216_CHEAP);
	_test_L216(45, L216_NORMAL);
	_test_L216(65, L216_EXPENSIVE);
	_test_L216(120.5, L216_TOOMUCH);
}