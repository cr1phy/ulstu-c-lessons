#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 1024
char s[MAX_LEN];

void L823(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* fin = fopen("C:\\Temp\\Lection12\\text3.txt", "rt");
	if (!fin) {
		printf("Входной файл не найден\n");
		return;
	}

	FILE* fout = fopen("C:\\Temp\\Lection12\\out3.txt", "wt");
	if (!fout) {
		fclose(fin);
		printf("Выходной файл не создаётся\n");
		return;
	}

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	
	while (!feof(fin)) {
		int has_latin = 0;
		if (fgets(s, MAX_LEN, fin) != NULL) {
			// идём только до '\0': дальше в s лежит хвост от прошлой строки
			for (int i = 0; s[i] != '\0' && !has_latin; i++) {
				if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
					has_latin = 1;
				}
			}
			fprintf(fout, has_latin ? "#%s" : "%s", s);
			printf(has_latin ? ">>> #%s" : ">>> %s", s);
		}
	}

	fclose(fout);
	fclose(fin);
}