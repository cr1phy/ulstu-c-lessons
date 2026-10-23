#include <stdio.h>
#include <Windows.h>

#define TEMPLATE_HTML_START "<!DOCTYPE html><html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" /><title>HTML Document</title></head><body>"
#define TEMPLATE_HTML_END "</body></html>"

void L831(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* fin = fopen("C:\\Temp\\Part3\\in1.txt", "rt");
	if (!fin) {
		printf("Не нашёл файл\n");
		return;
	}

	FILE* fout = fopen("C:\\Temp\\Part3\\out1.html", "wt");
	if (!fout) {
		fclose(fin);
		printf("Не могу создать файл\n");
		return;
	}

	fprintf(fout, TEMPLATE_HTML_START);
	while (1) {
		int c = fgetc(fin);
		if (c == EOF) {
			break;
		}
		if (c == '\n') {
			fprintf(fout, "<br>");
			continue;
		}
		fprintf(fout, "%c", c);
	}
	fprintf(fout, TEMPLATE_HTML_END);
	fflush(fout);

	printf("конец.\n");

	fclose(fout);
	fclose(fin);
}