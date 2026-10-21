#include <stdio.h>
#include "funcs.h"

void L812(void) {
	FILE* fin = fopen("in2.txt", "rt");
	if (fin == NULL) {
		printf("File `in2.txt` not found.\n");
		return;
	}

	FILE* fout = fopen("out2.txt", "wt");
	if (fout == NULL) {
		printf("File `out2.txt` can't be created!\n");
		fclose(fin);
		return;
	}

	int arr[3] = { 0, 0, 0 };
	for (int i = 0; i < 3; i++) {
		fscanf_s(fin, "%d", &arr[i]);
	}

	int max = arr[0];
	if (arr[1] > max) {
		max = arr[1];
	}
	if (arr[2] > max) {
		max = arr[2];
	}

	int bytes = fprintf_s(fout, "%d\n", max);
	printf("wrote %d bytes\n", bytes);

	fclose(fin);
	fclose(fout);
}