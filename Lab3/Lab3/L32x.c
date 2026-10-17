#include <stdio.h>

// 3.2.1
void Task1() {
	printf("Task1() START\n");

	int N, M;
	printf("N = ");
	scanf_s("%d", &N);
	printf("M = ");
	scanf_s("%d", &M);

	//if (N > 9 && M > 9) {
	//	printf("N или M больше 9");
	//}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%d ", i * 10 + j);
		}
		printf("\n");
	}

	printf("Task1() FINISH\n");
}

// 3.2.2
void Task2() {
	printf("Task2() START\n");

	int i = 1;
	do {
		int j = 1;
		do {
			printf("%2d ", i * j);
			j++;
		} while (j <= 4);
		printf("\n");
		i++;
	} while (i <= 3);

	printf("Task2() FINISH\n");
}

// 3.2.3
void Task3() {
	printf("Task3() START\n");

	int N = 3, i = 1;
	do {
		int j = 1;
		do {
			printf("%d ", j);	
			j++;
		} while (j <= i);
		printf("\n");
		i++;
	} while (i <= N);

	printf("Task3() FINISH\n");
}

// 3.2.4
void Task4() {
	printf("Task4() START\n");

	int M = 5;
	int i = 1;
	while (i <= M) {
		for (int x = M; x > 0; x--) {
			if (x <= i) {
				printf("%d ", x);
			}
			else {
				printf("  ");
			}
		}
		for (int y = 2; i >= y; y++) {
			printf("%d ", y);
		}
		printf("\n");
		i++;
	}

	printf("Task4() FINISH\n");
}


void L32() {
	int n = -1;
	do {
		printf("\n\n");
		printf("Выберите нужную вам операцию:\n");
		printf("1: Задача 1 (i * 10 + j) \n");
		printf("2: Задача 2 (Таблица Пифагора)\n");
		printf("3: Задача 3 (Рисунок по варианту)\n");
		printf("4: Задача 4 (Узор)");
		printf("\n");
		printf("0: Выйти из программы\n");
		scanf_s("%d", &n);

		switch (n) {
		case 1:
			Task1();
			break;
		case 2:
			Task2();
			break;
		case 3:
			Task3();
			break;
		case 4:
			Task4();
			break;
		}
	} while (n != 0);
}