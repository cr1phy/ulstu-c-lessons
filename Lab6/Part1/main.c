#include <stdio.h>
#include <Windows.h>

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

void printElements() {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

void keyboardInput() {
	printf("n = ");
	scanf_s("%d", &n);

	printf("input %d values: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}

void oddsX10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] *= 10;
		}
	}
}

int findMin() {
	int result = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < result)
			result = arr[i];
	}
	return result;
}

int countBigger10() {
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 10) result++;
	}
	return result;
}

int findLastEven() {
	for (int x = n - 1; x >= 0; x--) {
		if (arr[x] % 2 == 0) return x;
	}
	return -1;
}

int findIndexMin() {
	int index = 0;
	for (int i = index; i < n; i++) {
		if (arr[i] < arr[index]) index = i;
	}
	return index;
}

int findIndexMax() {
	int index = 0;
	for (int i = index; i < n; i++) {
		if (arr[i] > arr[index]) index = i;
	}
	return index;
}

int findFirstEven() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) return i;
	}
	return -1;
}

void deleteElement(int index) {
	if (0 <= index && index < n) { 
		for (int i = index; (i + 1) < n; i++) {
			arr[i] = arr[i + 1];
		}
		//arr[n - 1] = NULL;
		n--;
	}
	else {
		printf("индекс не в диапазоне [0; n)\n");
	}
}

void insertElement(int index, int value) {
	//if ((n + 1) > NUM_ELEMENTS) {
	//	printf("число элементов превышает максималку.");
	//	return;
	//}
	if (0 <= index && index <= n) {
		for (int i = n; i > index; i--) {
			arr[i] = arr[i - 1];
		}
		arr[index] = value;
		n++;
	}
	else {
		printf("индекс не в диапазоне [0; n]\n");
	}
}

double arrayAverage() {
	double summ = 0.0;
	for (int i = 0; i < n; i++) {
		summ += arr[i];
	}
	return summ / n;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
		if (n == 0)
			printf("Массив пуст\n");
		else {
			printf("Содержимое массива: < ");
			printElements();
			printf(">\n");
		}
		printf("\nВыберите нужную вам операцию:\n");
		printf("1: Ввести с клавиатуры массив\n");
		printf("2: x10 для всех нечетных элементов\n");
		printf("3: Найти минимальный элемент\n");
		printf("4: Сколько элементов > 10\n");
		printf("5: x2 для последнего четного\n");
		printf("6: Сколько чётных левее минимального\n");
		printf("7: x10 для нечётных правее минимального\n");
		printf("8: Поменять местами минимальный и максимальный\n");
		printf("9: Все четные элементы массива умножить на -1\n");
		printf("10: Все элементы массива, имеющие значения меньше 4 заменить на 4\n");
		printf("11: Все нечетные элементы заменить на 1\n");
		printf("12: Все элементы стоящие между максимальным и минимальным увеличить в 10 раз\n");
		printf("13: Все элементы между первым и последним четным увеличить в 100 раз\n");
		printf("\n");
		printf("21: Удалить заданный элемент\n");
		printf("22: Вставить элемент в заданное место\n");
		printf("23: Удалить минимальный элемент\n");
		printf("24: Перед минимальным элементом вставить 0\n");
		printf("25: Удалить все четные элементы\n");
		printf("26: Продублировать все четные элементы\n");
		printf("27: Добавить в начало элемент, равный минимальному\n");
		printf("28: Удалить из массива все элементы, значение которых меньше 4\n");
		printf("29: Удалить последний из четных элементов\n");
		printf("30: Удалить четные элементы, имеющие значение больше среднего арифметического всех элементов массива\n");
		printf("31: Удалить цепочки из четных элементов, состоящие менее чем из трех элементов\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		printf(">>> ");
		scanf_s("%d", &item);

		switch (item) {
		case 1:
			keyboardInput();
			break;
		case 2:
			oddsX10();
			break;
		case 3:
		{
			int min = findMin();
			printf("min = %d\n", min);
		}
		break;
		case 4:
		{
			int count = countBigger10();
			printf("Элементы > 10: %d\n", count);
		}
		break;
		case 5:
		{
			int index = findLastEven();
			if (index >= 0) arr[index] *= 2;
			else printf("Не найдено четных элементов\n");
		}
		break;
		case 6:
		{
			int index = findIndexMin();
			printf("Индекс минимального элемента = %d\n", index);

			int cnt = 0;
			for (int i = 0; i < index; i++) {
				if (arr[i] % 2 == 0) cnt++;
			}
			printf("Левее минимального %d четных элементов\n", cnt);
		}
		break;
		case 7:
		{
			int index = findIndexMin();
			printf("Индекс минимального элемента = %d\n", index);

			for (int i = index + 1; i < n; i++) {
				if (arr[i] % 2 != 0) arr[i] *= 10;
			}
		}
		break;
		case 8:
		{
			int indexMin = findIndexMin();
			printf("Индекс минимального элемента = %d\n", indexMin);
			int indexMax = findIndexMax();
			printf("Индекс максимального элемента = %d\n", indexMax);

			int tmp = arr[indexMin];
			arr[indexMin] = arr[indexMax];
			arr[indexMax] = tmp;
		}
		break;
		case 9:
		{
			for (int i = 0; i < n; i++) {
				if (arr[i] % 2 == 0) arr[i] *= -1;
			}
		}
		break;
		case 10:
		{
			for (int i = 0; i < n ; i++) {
				if (arr[i] < 4) arr[i] = 4;
			}
		}
		break;
		case 11:
		{
			for (int i = 0; i < n; i++) {
				if (arr[i] % 2 != 0) arr[i] = 1;
			}
		}
		break;
		case 12:
		{
			int indexMin = findIndexMin();
			printf("Индекс минимального элемента = %d\n", indexMin);
			int indexMax = findIndexMax();
			printf("Индекс максимального элемента = %d\n", indexMax);

			for (int i = indexMin + 1; i < (indexMax - 1); i++) {
				arr[i] *= 10;
			}
		}
		break;
		case 13:
		{
			int firstEven = findFirstEven();
			int lastEven = findLastEven();
			if (firstEven == -1) {
				printf("чётные не найдены.\n");
			}
			
			for (int i = firstEven; i < lastEven; i++) {
				arr[i] *= 100;
			}
		}
		break;
		case 21:
		{
			printf("Индекс удаляемого элемента = ");
			int index;
			scanf_s("%d", &index);
			deleteElement(index);
		}
		break;
		case 22:
		{
			printf("Перед каким элементом нужно вставить новый? Индекс = ");
			int index;
			scanf_s("%d", &index);

			printf("Значение, которое нужно вставить = ");
			int value;
			scanf_s("%d", &value);

			insertElement(index, value);
		}
		break;
		case 23:
		{
			int index = findIndexMin();
			deleteElement(index);
		}
		break;
		case 24:
		{
			int indexMin = findIndexMin();
			printf("Индекс минимального элемента = %d\n", indexMin);

			insertElement(indexMin, 0);
		}
		break;
		case 25:
		{
			int i = 0;
			while (i < n) {
				if (arr[i] % 2 == 0) {
					deleteElement(i);
					i--;
				}
				i++;
			}
		}
		break;
		case 26:
		{
			int i = 0;
			while (i < n) {
				if (arr[i] % 2 == 0) {
					insertElement(i, arr[i]);
					i++;
				}
				i++;
			}
		}
		break;
		case 27:
		{
			int minimal = findMin();
			insertElement(0, minimal);
		}
		break;
		case 28:
		{
			int i = 0;
			while (i < n) {
				if (arr[i] < 4) {
					deleteElement(i);
					i--;
				}
				i++;
			}
		}
		break;
		case 29: 
		{
			int i = findLastEven();
			if (i == -1) {
				printf("Чётных нет!\n");
			}
			else {
				deleteElement(i);
			}
		}
		break;
		case 30:
		{
			double avg = arrayAverage();
			printf("Среднее арифметическое массива = %.2lf", avg);
			
			int j = 0;
			while (j < n) {
				if (arr[j] % 2 == 0 && arr[j] > avg) {
					deleteElement(j);
					j--;
				}
				j++;
			}
		}
		break;
		case 31:
		{
			int i = 0;
			int evens_count = 0;
			while (i < n) {
				if (arr[i] % 2 == 0) {
					evens_count++;
				}
				else {
					if (evens_count >= 3) {
						evens_count = 0;
					}
					else {
						while (evens_count > 0) {
							i--;
							deleteElement(i);
							evens_count--;
						}
					}
				}
				i++;
			} 
		}
		break;
		}
	} while (item != 0);
}
