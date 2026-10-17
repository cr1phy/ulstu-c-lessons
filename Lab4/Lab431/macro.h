#pragma once

#define MAX_OF_THREE(x, y, z, result) do {\
	int max = (x);\
	if (max < (y)) {\
		max = (y);\
	}\
	if (max < (z)) {\
		max = (z);\
	}\
	(result) = max;\
} while (0);

#define FACTORIAL(n, result) do {\
	int s = 1;\
	for (int i = 1; i <= (n); i++) {\
		s *= i;\
	}\
	(result) = s;\
} while (0);

void macro_task_max_of_three();
void macro_task_factorial();