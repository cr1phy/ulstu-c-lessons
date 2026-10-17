#include <stdio.h>
#include <math.h>

void print1_10() {
	int a = 1;
	do {
		printf("%d ", a);
		a++;
	} while (a <= 10);
}

void print10_1() {
	int a = 10;
	do {
		printf("%d ", a);
		a--;
	} while (a >= 1);
}

void print5Odds() {
	int a = 1, i = 1;
	do {
		printf("%d ", a);
		a += 2;
		i++;
	} while (i <= 5);
}

// 3.1.2
void print100_10_while() {
	int a = 100;
	while (a >= 10) {
		printf("%d ", a);
		a -= 10;
	}
}

// 3.1.3
void print1000_100_while() {
	int a = 1000;
	while (a >= 100) {
		printf("%d ", a);
		a -= 100;
	}
}

void print1000_100_goto() {
	int a = 1000;
printer:
	printf("%d ", a);
	a -= 100;
	if (a >= 100) goto printer;
}

// 3.1.4
void hard_percents() {
	int s = 10000, n = 10, year = 1;
	printf("s = %d, n = %d\n", s, n);

	while (year <= 10) {
		s += (int)(s * n * 0.01);
		printf("через %d лет: %d\n", year, s);
		year++;
	}
}

// 3.1.5
void print1000_0_stepN() {
	int N = 22, x = 1000;

	while (x > 0) {
		printf("%d ", x);
		x -= N;
	}
	printf("0");
}

// 3.1.6
int _factor(int n) {
	switch (n) {
	case 0:
		printf("0 ");
		return 0;
	case 1:
		printf("1 ");
		return 1;
	default:
		printf("%d", n);
		return _factor(n - 1) * _factor(n - 2);
	}
}

void factorials() {
	int n, count = 1;
	printf("N = ");
	scanf_s("%d", &n);
	
	while (count <= n) {
		int s = 1;
		for (int x = 1; x <= count; x++) {
			s *= x;
		}
		printf("%d ", s);
		count++;
	}
}

void factorials_goto() {
	int n, count = 1, s, x;
	printf("N = ");
	scanf_s("%d", &n);

main_fact:
	if (count > n) goto end;
	s = 1;
	x = 1;
inner_fact:
	s *= x;
	x++;
	if (x <= count) goto inner_fact;
	printf("%d ", s);
	count++;
	goto main_fact;
end:
	printf("\n");
}

// 3.1.7
int _fib(int n) {
	switch (n) {
	case 0:
		return 0;
	case 1:
		return 1;
	default:
		return _fib(n - 2) + _fib(n - 1);
	}
}

void fibonacci() {
	int n, count = 0;
	printf("N = ");
	scanf_s("%d", &n);

	while (count < n) {
		int result = _fib(count);
		printf("%d ", result);
		count++;
	}
}

// 3.1.8
void _fa(int n) {
	for (int d = 2; d <= n / d; d++) { 
		while (n % d == 0) {
			printf("%d ", d);
			n /= d;
		}
	}
	if (n > 1) printf("%d", n);
	printf("\n");
}

void factors() {
	int n;
	printf("N = ");
	scanf_s("%d", &n);
	_fa(n);
}



void L31() {
	int n;
	do {
		printf("\n\n");
		printf("Выберите нужную вам операцию:\n");
		printf("1: Вывести числа от 1 до 10\n");
		printf("2: Вывести числа от 10 до 1\n");
		printf("3: Вывести 5 первых нечетных чисел, начиная с 1\n");
		printf("11: Вывести числа от 100 до 10 (while)\n");
		printf("12: Вывести числа от 1000 до 100 (while)\n");
		printf("13: Вывести состояние счёта\n");
		printf("20: Вывести числа от 1000 до 0 с шагом N\n");
		printf("21: Вывести N первые факториалы\n");
		printf("22: Вывести N первые числа Фибоначчи\n");
		printf("23: Разложить число N на простые множители\n");
		// 3.1.9 / 3.1.10
		printf("31: Вывести числа от 1000 до 100 (if goto)\n");
		printf("32: Вывести N первые факториалы (if goto)\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			print1_10();
			break;
		case 2:
			print10_1();
			break;
		case 3:
			print5Odds();
			break;
		case 11:
			print100_10_while();
			break;
		case 12:
			print1000_100_while();
			break;
		case 13:
			hard_percents();
			break;
		case 20:
			print1000_0_stepN();
			break;
		case 21:
			factorials();
			break;
		case 22:
			fibonacci();
			break;
		case 23:
			factors();
			break;
		case 31:
			print1000_100_goto();
			break;
		case 32:
			factorials_goto();
			break;
		}
	} while (n != 0);
}
