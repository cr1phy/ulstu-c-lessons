#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 80
char s[MAX_LEN];

void L821(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Жмышенко Валерий\n");
	printf("Задача 8.1\n");

	FILE* fin = fopen("C:\\Temp\\Lection12\\text1.txt", "rt");
	if (!fin) {
		printf("Входной файл не найден");
		return;
	}

	FILE* fout = fopen("C:\\Temp\\Lection12\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		fclose(fin);
		return;
	}

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	while (!feof(fin)) {
		if (fgets(s, MAX_LEN, fin) != NULL) {
			for (int i = 0; s[i] != 0; i++) {
				if (s[i] == '\t') s[i] = '%';
			}
			fprintf(fout, "%s", s);
			printf(">>> %s", s);
		}
	}
	
	fclose(fout);
	fclose(fin);
}