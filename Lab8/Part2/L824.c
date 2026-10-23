#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 1024
char s[MAX_LEN];

void L824(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* fin = fopen("C:\\Temp\\Lection12\\text4.txt", "rt");
	if (!fin) {
		printf("Входной файл не найден\n");
		return;
	}

	FILE* fout = fopen("C:\\Temp\\Lection12\\out4.txt", "wt");
	if (!fout) {
		fclose(fin);
		printf("Выходной файл не создаётся\n");
		return;
	}

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);


	while (!feof(fin)) {
		if (fgets(s, MAX_LEN, fin) != NULL) {
			for (int i = 0; s[i] != 0; i++) {
				// если русские буквы, то они больше, чем 127, поэтому беззнаковый чар
				if (isalpha((unsigned char)s[i])) s[i] = '&';
			}
			fprintf(fout, "%s", s);
			printf(">>> %s", s);
			fflush(fout);
		}
	}

	fclose(fout);
	fclose(fin);
}