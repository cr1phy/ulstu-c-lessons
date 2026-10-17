#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK(expr) \
	do { \
		if (expr) \
			printf("  [OK]   %s\n", #expr); \
		else \
			printf("  [FAIL] %s  (%s:%d)\n", #expr, __FILE__, __LINE__); \
	} while (0)

#define CHECK_STR(actual, expected) \
	do { \
		const char* actual_ = (actual); \
		const char* expected_ = (expected); \
		if (actual_ != NULL && strcmp(actual_, expected_) == 0) \
			printf("  [OK]   %s == \"%s\"\n", #actual, expected_); \
		else \
			printf("  [FAIL] %s: \"%s\", ожидалось \"%s\"  (%s:%d)\n", \
				#actual, actual_ != NULL ? actual_ : "(null)", expected_, __FILE__, __LINE__); \
	} while (0)

#define CHECK_NEW(create, input, expected) \
	do { \
		char* result_ = create(input); \
		if (result_ != NULL && strcmp(result_, (expected)) == 0) \
			printf("  [OK]   %s(\"%s\") == \"%s\"\n", #create, (input), (expected)); \
		else \
			printf("  [FAIL] %s(\"%s\"): \"%s\", ожидалось \"%s\"  (%s:%d)\n", \
				#create, (input), result_ != NULL ? result_ : "(null)", (expected), __FILE__, __LINE__); \
		free(result_); \
	} while (0)
