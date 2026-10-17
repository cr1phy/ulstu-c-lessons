#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "L72.h"
#include "input.h"

char* CreateNewString_L7261(char s1[]) {
	int length = 0, hasDigits = 0;
	for (int i = 0; s1[i] != '\0'; i++) {
		if (!hasDigits && isdigit((unsigned char)s1[i]))
			hasDigits = 1;
		length++;
	}

	int total_len = length + 2 + hasDigits;
	char* result = (char*)malloc((total_len + 1) * sizeof(char));
	if (result == NULL)
		return NULL;

	int j = 0;
	if (hasDigits)
		for (j = 0; j < 3; j++)
			result[j] = '+';

	for (int i = 0; i < length; i++)
		result[j++] = s1[i];

	if (!hasDigits)
		while (j < total_len)
			result[j++] = '*';

	result[total_len] = '\0';
	return result;
}

char* CreateNewStringP(char* s1) {
	int length = 0, hasDigits = 0;
	for (char* p = s1; *p != '\0'; p++) {
		if (!hasDigits && isdigit((unsigned char)*p))
			hasDigits = 1;
		length++;
	}

	char* result = (char*)malloc(length + (hasDigits ? 3 : 2) + 1);
	if (result == NULL)
		return NULL;

	char* w = result;
	if (hasDigits)
		for (int k = 0; k < 3; k++)
			*w++ = '+';

	for (char* p = s1; *p != '\0'; )
		*w++ = *p++;

	if (!hasDigits) {
		*w++ = '*';
		*w++ = '*';
	}

	*w = '\0';
	return result;
}

static void demo(char* (*create)(char*)) {
	char s1[100];

	printf("s1=");
	if (!read_line(s1, sizeof s1)) return;

	char* s2 = create(s1);
	if (s2 == NULL) {
		printf("Не удалось выделить память\n");
		return;
	}

	printf("s1=%s\n", s1);
	printf("s2=%s\n", s2);

	free(s2);
}

void demo_L7261(void) {
	demo(CreateNewString_L7261);
}

void demo_L7262(void) {
	demo(CreateNewStringP);
}
