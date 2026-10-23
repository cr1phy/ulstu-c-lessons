#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 1024
char s[MAX_LEN];

void L825(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* fin = fopen("C:\\Temp\\Lection12\\text5.txt", "rt");
	if (!fin) {
		printf("Входной файл не найден\n");
		return;
	}

	FILE* fout = fopen("C:\\Temp\\Lection12\\out5.txt", "wt");
	if (!fout) {
		fclose(fin);
		printf("Выходной файл не создаётся\n");
		return;
	}

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	while (!feof(fin)) {
		if (fgets(s, MAX_LEN, fin) != NULL) {
			int count = 0;
			for (int i = 0; s[i] != 0; i++) {
				if ((unsigned char)s[i] == (unsigned char)';') count++;
			}
			fprintf(fout, "%d;%s", count, s);
			printf(">>> %d; %s", count, s);
			fflush(fout);
		}
	}
}