#include <stdio.h>
#include "examples.h"

void long_factorial_processing() {
    printf("%s() start!\n", __func__);

    int n = 1;
    long fact = 1, prevFact = 1;

    while (n < 100) {
        fact = 1;
        int i = 1;
        do {
            fact = fact * i;
            i = i + 1;
        } while (i <= n);

        printf("<%li (%d!) %d>\n", fact, n, (fact / prevFact));

        prevFact = fact;

        n += 1;
    }

    printf("%s() finish!\n", __func__);
}

void long_input_processing() {
    printf("%s() start!\n", __func__);

    long x;
    long a;
    printf("sizeof [long]: %zd\n", sizeof(x));
    printf("Enter an initial long: ");
    scanf_s("%ld", &x);
    printf("Enter a multiplier (>1): ");
    scanf_s("%ld", &a);
    if (a <= 1) {
        printf("multiplier must be > 1\n");
        return;
    }

    int i = 0;
    while (x > 0) {
        printf("<%ld (%d)>\n", x, i);
        x = (long)((unsigned long)x * (unsigned long)a);
        i++;
    }
    printf("OVERFLOW [long]: <%ld (%d)>\n", x, i);

    printf("%s() finish!\n", __func__);
}

void long_examples() {
    long_factorial_processing();
    long_input_processing();
}
