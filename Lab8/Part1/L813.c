#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <limits.h>

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

void clearInputLine(void) {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {}
}

// Проверка результата scanf_s не позволяет использовать неинициализированные данные.
int readNumber(int* value) {
	if (scanf_s("%d", value) == 1) return 1;
	clearInputLine();
	printf("Ошибка ввода: требуется целое число.\n");
	return 0;
}

// Не допускаем переполнение int при умножении.
void multiplyElement(int index, int factor) {
	long long result = (long long)arr[index] * factor;
	if (result < INT_MIN || result > INT_MAX) {
		printf("Переполнение int при умножении элемента с индексом %d.\n", index);
		return;
	}
	arr[index] = (int)result;
}

void printElements(void) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

void keyboardInput(void) {
	int count;
	printf("n = ");
	if (!readNumber(&count)) return;
	if (count < 0 || count > NUM_ELEMENTS) {
		printf("Размер массива должен быть от 0 до %d.\n", NUM_ELEMENTS);
		clearInputLine();
		return;
	}

	int values[NUM_ELEMENTS];
	printf("input %d values: ", count);
	for (int i = 0; i < count; i++) {
		if (!readNumber(&values[i])) {
			printf("Массив не изменён из-за ошибки ввода.\n");
			return;
		}
	}
	for (int i = 0; i < count; i++) arr[i] = values[i];
	n = count;
}

void oddsX10(void) {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			multiplyElement(i, 10);
		}
	}
}

int findMin(void) {
	if (n == 0) return 0;
	int result = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < result)
			result = arr[i];
	}
	return result;
}

int countBigger10(void) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 10) result++;
	}
	return result;
}

int findLastEven(void) {
	for (int x = n - 1; x >= 0; x--) {
		if (arr[x] % 2 == 0) return x;
	}
	return -1;
}

int findIndexMin(void) {
	if (n == 0) return -1;
	int index = 0;
	for (int i = index; i < n; i++) {
		if (arr[i] < arr[index]) index = i;
	}
	return index;
}

int findIndexMax(void) {
	if (n == 0) return -1;
	int index = 0;
	for (int i = index; i < n; i++) {
		if (arr[i] > arr[index]) index = i;
	}
	return index;
}

int findFirstEven(void) {
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
		n--;
	}
	else {
		printf("индекс не в диапазоне [0; n)\n");
	}
}

void insertElement(int index, int value) {
	if (n >= NUM_ELEMENTS) {
		printf("Вставка невозможна: массив заполнен (максимум %d элементов).\n", NUM_ELEMENTS);
		return;
	}
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

double arrayAverage(void) {
	double summ = 0.0;
	for (int i = 0; i < n; i++) {
		summ += arr[i];
	}
	return n > 0 ? summ / n : 0.0;
}

// сохранение
void save(void) {
	FILE* fout = fopen("mas813.txt", "w");
	if (!fout) {
		printf("файл не создаётся.\n\n");
		return;
	}
	
	for (int i = 0; i < n; i++) {
		fprintf(fout, "%d\n", arr[i]);
	}

	fclose(fout);
}

// загрузка
void load(void) {
	FILE* fin = fopen("mas813.txt", "rt");
	if (!fin) {
		printf("файла нет.\n\n");
		return;
	}

	n = 0;

	int temp = 0;
	while (fscanf_s(fin, "%d", &temp) == 1) {
		if (n >= NUM_ELEMENTS) {
			printf("В файле больше %d чисел, лишние пропущены.\n", NUM_ELEMENTS);
			break;
		}
		arr[n++] = temp;
	}

	fclose(fin);
}

void L813(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	load();

	int item = 0;
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
		printf("101. Загрузка из файла\n");
		printf("102. Выгрузить в файл\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		printf(">>> ");
		int read = scanf_s("%d", &item);
		if (read == EOF) break;
		if (read != 1) {
			clearInputLine();
			printf("Неизвестная команда: введите число из меню.\n");
			continue;
		}
		// Операции с минимумом, максимумом и средним требуют непустой массив.
		if (n == 0 && (item == 3 || item == 6 || item == 7 || item == 8 ||
			item == 12 || item == 23 || item == 24 || item == 27 || item == 30)) {
			printf("Массив пуст: сначала введите элементы.\n");
			continue;
		}

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
			if (index >= 0) multiplyElement(index, 2);
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
				if (arr[i] % 2 != 0) multiplyElement(i, 10);
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
				if (arr[i] % 2 == 0) multiplyElement(i, -1);
			}
		}
		break;
		case 10:
		{
			for (int i = 0; i < n; i++) {
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

			int left = indexMin < indexMax ? indexMin : indexMax;
			int right = indexMin > indexMax ? indexMin : indexMax;
			for (int i = left + 1; i < right; i++) {
				multiplyElement(i, 10);
			}
		}
		break;
		case 13:
		{
			int firstEven = findFirstEven();
			int lastEven = findLastEven();
			if (firstEven == -1) {
				printf("Чётные не найдены.\n");
			}
			else {
				for (int i = firstEven + 1; i < lastEven; i++) {
					multiplyElement(i, 100);
				}
			}
		}
		break;
		case 21:
		{
			printf("Индекс удаляемого элемента = ");
			int index;
			if (readNumber(&index)) deleteElement(index);
		}
		break;
		case 22:
		{
			printf("Перед каким элементом нужно вставить новый? Индекс = ");
			int index;
			if (!readNumber(&index)) break;

			printf("Значение, которое нужно вставить = ");
			int value;
			if (!readNumber(&value)) break;

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
			int evenCount = 0;
			for (int j = 0; j < n; j++)
				if (arr[j] % 2 == 0) evenCount++;
			if (n + evenCount > NUM_ELEMENTS) {
				printf("Недостаточно места для дублирования всех чётных элементов.\n");
				break;
			}
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
			int write = 0;
			int i = 0;
			while (i < n) {
				if (arr[i] % 2 != 0) {
					arr[write++] = arr[i++];
					continue;
				}
				int start = i;
				while (i < n && arr[i] % 2 == 0) i++;
				// Оставляем только цепочки длиной три и более.
				if (i - start >= 3) {
					for (int j = start; j < i; j++) arr[write++] = arr[j];
				}
			}
			n = write;
		}
		break;
		case 101:
			load();
			break;
		case 102:
			save();
			break;
		}
	} while (item != 0);
}
