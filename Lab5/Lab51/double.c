#include <stdio.h>
#include <math.h>
#include <float.h>
#include "examples.h"

void double_processing() {
    printf("%s() start!\n", __func__);

    double f = 1.23456789012345678901234567890;
    int i = 0;
    while (i < 1000) {
        printf("<%60.30f (%d)>\n", f, i);
        f *= 10;
        i += 1;
    }

    printf("sizeof: f = %zd,   i = %zd", sizeof(f), sizeof(i));

    printf("%s() finish!\n", __func__);
}

void double_input_processing() {
    printf("%s() start!\n", __func__);

    double d;
    double k;
    printf("sizeof [double]: %zd\n", sizeof(d));
    printf("DBL_MAX = %e\n", DBL_MAX);
    printf("Enter an initial double: ");
    scanf_s("%lf", &d);
    printf("Enter a multiplier (>1): ");
    scanf_s("%lf", &k);
    if (k <= 1.0) {
        printf("multiplier must be > 1\n");
        return;
    }

    int i = 0;
    while (!isinf(d)) {
        printf("<%e (%d)>\n", d, i);
        d *= k;
        i++;
    }
    printf("OVERFLOW [double]: <%e (%d)>\n", d, i);

    double big = 9007199254740992.0;
    double bigger = big + 1.0;
    printf("precision [double]: %.1f + 1 = %.1f\n", big, bigger);

    printf("%s() finish!\n", __func__);
}

void double_examples() {
    double_processing();
    double_input_processing();
}
