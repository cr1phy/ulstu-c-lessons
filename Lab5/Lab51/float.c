#include <stdio.h>
#include <math.h>
#include <float.h>
#include "examples.h"

void float_processing() {
    printf("%s() start!\n", __func__);

    float f = 1.23456789012345678901234567890;
    int i = 0;
    while (i < 1000) {
        printf("<%60.30f (%d)>\n", f, i);
        f *= 10;
        i += 1;
    }

    printf("sizeof: f = %d,   i = %d", sizeof(f), sizeof(i));

    printf("%s() finish!\n", __func__);
}

void float_input_processing() {
    printf("%s() start!\n", __func__);

    float f;
    float k;
    printf("sizeof [float]: %zd\n", sizeof(f));
    printf("FLT_MAX = %e\n", FLT_MAX);
    printf("Enter an initial float: ");
    scanf_s("%f", &f);
    printf("Enter a multiplier (>1): ");
    scanf_s("%f", &k);
    if (k <= 1.0f) {
        printf("multiplier must be > 1\n");
        return;
    }

    int i = 0;
    while (!isinf(f)) {
        printf("<%e (%d)>\n", f, i);
        f *= k;
        i++;
    }
    printf("OVERFLOW [float]: <%e (%d)>\n", f, i);

    float big = 16777216.0f;
    float bigger = big + 1.0f;
    printf("precision [float]: %.1f + 1 = %.1f\n", big, bigger);

    printf("%s() finish!\n", __func__);
}

void float_examples() {
    float_processing();
    float_input_processing();
}
