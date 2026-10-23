#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <Windows.h>

#define TEMPLATE_HTML_START "<!DOCTYPE html><html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" /><title>HTML Document</title></head><body>"
#define TEMPLATE_HTML_END "</body></html>"

#define MAX_LEN 128

int isdelim(char ch) {
	return
		(ch == '\n' || ch == '\t') ||
		(ch >= ' ' && ch <= '/') ||
		(ch >= ':' && ch <= '@') ||
		(ch >= '[' && ch <= '`') ||
		(ch >= '{' && ch <= '~') ||
		(ch == '\0');
}

char word[MAX_LEN];
int length = 0;

void print_word(FILE* fout, const char* w) {
	if (w[0] == '\0')
		return;

	int rest_lower = 1;
	for (int i = 1; w[i] != '\0'; i++) {
		if (!islower((unsigned char)w[i])) {
			rest_lower = 0;
			break;
		}
	}

	unsigned char first = (unsigned char)w[0];

	if (rest_lower && isupper(first))
		fprintf(fout, "<b>%s</b>", w);
	else if (rest_lower && islower(first))
		fprintf(fout, "<i>%s</i>", w);
	else
		fprintf(fout, "%s", w);
}

void L832(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* fin = fopen("C:\\Temp\\Part3\\text2.txt", "rt");
	if (!fin) {
		printf("Не нашёл файл\n");
		return;
	}

	FILE* fout = fopen("C:\\Temp\\Part3\\text2.html", "wt");
	if (!fout) {
		fclose(fin);
		printf("Не могу создать файл\n");
		return;
	}

	fprintf(fout, TEMPLATE_HTML_START);

	int c;
	while ((c = fgetc(fin)) != EOF) {
		if (isdelim((char)c)) {
			word[length] = '\0';
			print_word(fout, word);
			length = 0;
			// <br> только после слова, иначе последнее слово строки уедет на следующую
			if (c == '\n') {
				fprintf(fout, "<br>");
			}
			fputc(c, fout);
		}
		else if (length < MAX_LEN - 1) {
			word[length++] = (char)c;
		}
	}

	word[length] = '\0';
	print_word(fout, word);
	length = 0;

	fprintf(fout, TEMPLATE_HTML_END);

	fclose(fout);
	fclose(fin);
}