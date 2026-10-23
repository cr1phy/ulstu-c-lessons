#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <Windows.h>

#define MAX_LEN 128
char s[MAX_LEN];

void L822(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* fin = fopen("C:\\Temp\\Lection12\\text2.txt", "rt");
	if (!fin) {
		printf("Входной файл не найден");
		return;
	}

	FILE* fout = fopen("C:\\Temp\\Lection12\\out2.txt", "wt");
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
				// русские буквы > 127: без unsigned char будет отрицательное число и ассерт
				s[i] = (char)toupper((unsigned char)s[i]);
			}
			fprintf(fout, "%s", s);
			printf(">>> %s", s);
		}
	}

	fclose(fout);
	fclose(fin);
}