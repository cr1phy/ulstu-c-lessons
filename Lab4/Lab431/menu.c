#include <stdio.h>
#include "menu.h"
#include "l2.h"
#include "l3.h"
#include "l4.h"
#include "macro.h"

void choose_lab() {
	int n = -1;
	do {
		printf("Введите число для выбора лабораторной работы [1-3].\n");
		printf("4. Функции в виде макросов.\n");
		printf("0. Выход из программы.\n");
		printf(">>> ");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			choose_task1();
			break;
		case 2:
			choose_task2();
			break;
		case 3:
			choose_task3();
			break;
		case 4:
			choose_macro_task();
		case 0:
			break;
		default:
			printf("Введите корректное число. Только 0, 1, 2, 3.");
			break;
		}
	} while (n != 0);
}

void choose_task1() {
	int n = -1;
	do {
		printf("Введите число для выбора задачи в л/р #1.\n");
		printf("1. Максимальное из трёх чисел\n");
		printf("2. Расчёт суммы вклада\n");
		printf("3. Расчёт стоимости с учётом амортизации\n");
		printf("0. Назад\n");
		printf(">>> ");
		scanf_s("%d", &n);

		switch (n) {
		case 1:
			task_max_of_three();
			break;
		case 2:
			task_deposit_amount();
			break;
		case 3:
			task_depreciated_price();
			break;
		case 0:
			break;
		default:
			printf("Введите корректное число. Только 0, 1, 2, 3.\n");
			break;
		}
	} while (n != 0);
}

void choose_task2() {
	int n = -1;
	do {
		printf("Введите число для выбора задачи в л/р #2.\n");
		printf("1. Расчёт сложных процентов\n");
		printf("2. Вычисление факториала\n");
		printf("3. Вычисление числа Фибоначчи\n");
		printf("0. Назад\n");
		printf(">>> ");
		scanf_s("%d", &n);

		switch (n) {
		case 1:
			task_compound_interest();
			break;
		case 2:
			task_factorial();
			break;
		case 3:
			task_fibonacci();
			break;
		case 0:
			break;
		default:
			printf("Введите корректное число. Только 0, 1, 2, 3.\n");
			break;
		}
	} while (n != 0);
}

void choose_task3() {
	int n = -1;
	do {
		printf("Введите число для выбора задачи в л/р #3.\n");
		printf("1. Расчёт штрафа за превышение скорости\n");
		printf("2. Расчёт расхода топлива\n");
		printf("3. Расчёт подоходного налога\n");
		printf("0. Назад\n");
		printf(">>> ");
		scanf_s("%d", &n);

		switch (n) {
		case 1:
			task_speeding_fine();
			break;
		case 2:
			task_fuel_consumption();
			break;
		case 3:
			task_income_tax();
			break;
		case 0:
			break;
		default:
			printf("Введите корректное число. Только 0, 1, 2, 3.\n");
			break;
		}
	} while (n != 0);
}

void choose_macro_task() {
	int n = -1;
	do {
		printf("Выберите задачу, собранную с помощью макроса.\n");
		printf("1. Максимальное из трёх\n");
		printf("2. Факториал\n");
		printf("0. Назад\n");
		printf(">>> ");
		scanf_s("%d", &n);
		
		switch (n) {
		case 1:
			macro_task_max_of_three();
			break;
		case 2:
			macro_task_factorial();
			break;
		case 0:
			break;
		default:
			printf("Введите корректное число. Только 0, 1, 2.\n");
			break;
		}
	} while (n != 0);
}