#include <stdio.h>
#include <Windows.h>

#define MAX_N 20

void L814() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// 1. загрузка из файла
	FILE* fin = fopen("in4.txt", "r");
	if (!fin) {
		printf("файла in4.txt не существует!\n");
		return;
	}

	// пропускаем BOM (EF BB BF), если файл сохранён как UTF-8 с BOM
	unsigned char bom[3];
	if (fread(bom, 1, 3, fin) != 3 || bom[0] != 0xEF || bom[1] != 0xBB || bom[2] != 0xBF)
		rewind(fin);

	int arr[MAX_N];
	int length = 0;
	if (fscanf_s(fin, "%d", &length) != 1 || length <= 0 || length > MAX_N) {
		printf("Неверная длина! %d\n", length);
		fclose(fin);
		return;
	}

	for (int i = 0; i < length; i++) {
		if (fscanf_s(fin, "%d", &arr[i]) != 1) {
			printf("В файле меньше чисел, чем %d\n", length);
			fclose(fin);
			return;
		}
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
	fprintf(fout, "%d\n", length);
	for (int i = 0; i < length; i++) {
		fprintf(fout, "%d ", arr[i]);
	}
	fprintf(fout, "\n");
	printf("Записано\n");
	
	fclose(fout);
}