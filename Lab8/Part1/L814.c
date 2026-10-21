#include <stdio.h>
#include <Windows.h>

int* arr;

void L814() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// 1. загрузка из файла
	FILE* fin = fopen("in4.txt", "r");
	if (!fin) {
		printf("файла in4.txt не существует!\n");
		return;
	}

	int length = 0;
	int result = fscanf_s(fin, "%d", &length);
	if (length <= 0) {
		printf("Неверная длина! %d\n", result);
		fclose(fin);
		return;
	}

	for (int i = 0; i < length; i++) {
		fscanf_s(fin, "%d", &arr[i]);
	}
	fclose(fin);

	// 2. Контрольный вывод
	printf("Массив до операций: [ ");
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf(" ]\n");

	// 3. Операции
	int minimal = arr[0];
	for (int i = 1; i < length; i++) {
		if (arr[i] < minimal)
			minimal = arr[i];
	}
	for (int i = 0; i < length; i++) {
		if (arr[i] % 3 == 0) arr[i] = minimal;
	}

	// 4. Контрольный вывод.
	printf("Массив после операций: [ ");
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf(" ]\n");

	// 5. Запись в файл
	FILE* fout = fopen("out4.txt", "w");
	if (!fout) {
		printf("Что-то не так при записи в файл\n");
		return;
	}
	for (int i = 0; i < length; i++) {
		fprintf(fin, "%d ", arr[i]);
	}
	printf("Записано\n");
	
	fclose(fout);
}