#include <stdio.h>
#include "funcs.h"

#define INFO "Жмышенко Валерий Альбертович, 13.12.1988, 33 года"

void L811(void) {
	FILE* fout = fopen("out1.txt", "wt");
	if (fout == NULL) {
		printf("File `out1.txt` can't be created!\n");
		return;
	}

	int len_bytes = fprintf_s(fout, INFO);
	printf("wrote %d bytes", len_bytes);

	fclose(fout);
}