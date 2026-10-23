#include <stdio.h>
#include "funcs.h"

#define INFO "Жмышенко Валерий Альбертович, 13.12.1988, 33 года"

void L811(void) {
	FILE* fout = fopen("hello.c", "wt");
	if (fout == NULL) {
		printf("File `hello.c` can't be created!\n");
		return;
	}

	fputs("#include <stdio.h>\n", fout);
	fputs("#include <Windows.h>\n", fout);
	fputs("\n", fout);
	fputs("int main(void) {\n", fout);
	fputs("\tSetConsoleOutputCP(1251);\n", fout);
	fprintf(fout, "\tprintf(\"%s\\n\");\n", INFO);
	fputs("\treturn 0;\n", fout);
	fputs("}\n", fout);

	fclose(fout);
	printf("File `hello.c` created\n");
}