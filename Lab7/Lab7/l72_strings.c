#include <stddef.h>
#include "L72.h"

int strlen_L7211(char s[]) {
	int i = 0;
	while (s[i] != '\0') i++;
	return i;
}

int strlen_L7212(char* s) {
	int i = 0;
	while (*s++ != '\0') i++;
	return i;
}

int strcmp_L7221(char s1[], char s2[]) {
	int i;
	for (i = 0; s1[i] == s2[i]; i++) {
		if (s1[i] == '\0')
			return 0;
	}

	return (unsigned char)s1[i] - (unsigned char)s2[i];
}

int strcmp_L7222(char* s1, char* s2) {
	while (*s1 != '\0' && *s1 == *s2) {
		s1++;
		s2++;
	}

	return (unsigned char)*s1 - (unsigned char)*s2;
}

void strcpy_L723(char s1[], char s2[]) {
	int i;
	for (i = 0; s2[i] != '\0'; i++) {
		s1[i] = s2[i];
	}
	s1[i] = '\0';
}

void strcat_L724(char* s1, char* s2) {
	int end_s1 = strlen_L7212(s1);
	int end_s2 = strlen_L7212(s2);

	for (int i = 0; i < end_s2; i++) {
		*(s1 + end_s1 + i) = *(s2 + i);
	}
	*(s1 + end_s1 + end_s2) = '\0';
}

char* strchr_L7251(char source[], char value) {
	if (value == '\0')
		return &source[strlen_L7211(source)];

	for (int i = 0; source[i] != '\0'; i++) {
		if (source[i] == value)
			return &source[i];

	}

	return NULL;
}

char* strchr_L7252(char* source, char value) {
	if (value == '\0')
		return source + strlen_L7212(source);

	while (*source != '\0') {
		if (*source == value)
			return source;
		source++;
	}

	return NULL;
}
