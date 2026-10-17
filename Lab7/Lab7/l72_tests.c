#include <stdio.h>
#include "check.h"
#include "L72.h"

void test_strlen(void) {
	printf("strlen_L7211 (массив):\n");
	CHECK(strlen_L7211("allo") == 4);
	CHECK(strlen_L7211("") == 0);
	CHECK(strlen_L7211("hello world") == 11);

	printf("strlen_L7212 (указатель):\n");
	CHECK(strlen_L7212("allo") == 4);
	CHECK(strlen_L7212("") == 0);
	CHECK(strlen_L7212("sosa") == 4);
}

void test_strcmp(void) {
	printf("strcmp_L7221 (массив):\n");
	CHECK(strcmp_L7221("abc", "abc") == 0);
	CHECK(strcmp_L7221("abc", "abd") < 0);
	CHECK(strcmp_L7221("abc", "ab") > 0);

	printf("strcmp_L7222 (указатель):\n");
	CHECK(strcmp_L7222("abc", "abc") == 0);
	CHECK(strcmp_L7222("abc", "abd") < 0);
	CHECK(strcmp_L7222("abc", "ab") > 0);
}

void test_strcpy(void) {
	char dst[16] = "xxxxxxxxxxxxxxx";

	printf("strcpy_L723:\n");
	strcpy_L723(dst, "hi");
	CHECK_STR(dst, "hi");
	strcpy_L723(dst, "");
	CHECK_STR(dst, "");
	strcpy_L723(dst, "hello");
	CHECK_STR(dst, "hello");
}

void test_strcat(void) {
	char a[16] = "abZZZZZZZZZZZZZ";
	char b[16] = "ab";
	char c[16] = "";
	a[2] = '\0';

	printf("strcat_L724:\n");
	strcat_L724(a, "cd");
	CHECK_STR(a, "abcd");
	strcat_L724(b, "");
	CHECK_STR(b, "ab");
	strcat_L724(c, "cd");
	CHECK_STR(c, "cd");
}

void test_strchr(void) {
	char s[] = "hello";

	printf("strchr_L7251 (массив):\n");
	CHECK(strchr_L7251(s, 'l') == s + 2);
	CHECK(strchr_L7251(s, 'z') == NULL);
	CHECK(strchr_L7251(s, '\0') == s + 5);

	printf("strchr_L7252 (указатель):\n");
	CHECK(strchr_L7252(s, 'l') == s + 2);
	CHECK(strchr_L7252(s, 'z') == NULL);
	CHECK(strchr_L7252(s, '\0') == s + 5);
}

void test_newstring(void) {
	printf("CreateNewString_L7261 (массив):\n");
	CHECK_NEW(CreateNewString_L7261, "abc123", "+++abc123");
	CHECK_NEW(CreateNewString_L7261, "abc", "abc**");
	CHECK_NEW(CreateNewString_L7261, "", "**");

	printf("CreateNewStringP (указатель):\n");
	CHECK_NEW(CreateNewStringP, "abc123", "+++abc123");
	CHECK_NEW(CreateNewStringP, "abc", "abc**");
	CHECK_NEW(CreateNewStringP, "", "**");
}

void test_all(void) {
	test_strlen();
	test_strcmp();
	test_strcpy();
	test_strcat();
	test_strchr();
	test_newstring();
}
