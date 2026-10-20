#include <stdio.h>

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

void L812(void) {
	FILE* fin = fopen("in2.txt", "rt");
	if (fin == NULL) {
		printf("File `in2.txt` not found.\n");
		return;
	}

	FILE* fout = fopen("out2.txt", "wt");
	if (fout == NULL) {
		printf("File `out2.txt` can't be created!\n");
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
}

int save(FILE* out, int length, int* arr) {
	for (int i = 0; i < length; i++) {
		fprintf(out, "%d\n", arr[i]);
	}
}

void L813(void) {
	FILE* fin = fopen("in3.txt", "rt");
	if (fin == NULL) {
		printf("File `in3.txt` not found.\n");
		return;
	}

	FILE* fout = fopen("out3.txt", "wt");
	if (fout == NULL) {
		printf("File `out3.txt` can't be created!\n");
		return;
	}

	int length = 0;
	int* arr;
	arr[0] = 1;
	arr[2] = 2;
	arr[3] = 8;
	arr[10] = 15;
	save(fout, length, arr);
}

int main(void) {
	//L811(); // TODO: сложное
	//L812();
	L813();

	return 0;
}