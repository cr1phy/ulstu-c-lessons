#include <stdio.h>
#include "examples.h"

void int_factorial_processing() {
    printf("%s() start!\n", __func__);

    int n = 1;
    int fact = 1, prevFact = 1;

    while (n < 100) {
        fact = 1;
        int i = 1;
        do {
            fact = fact * i;
            i = i + 1;
        } while (i <= n);

        printf("<%i (%d!) %d>\n", fact, n, (fact / prevFact));

        prevFact = fact;

        n += 1;
    }

    printf("%s() finish!\n", __func__);
}

void int_input_processing() {
    printf("%s() start!\n", __func__);

    int x;
    int a;
    printf("sizeof [int]: %zd\n", sizeof(x));
    printf("Enter an initial int: ");
    scanf_s("%d", &x);
    printf("Enter a multiplier (>1): ");
    scanf_s("%d", &a);
    if (a <= 1) {
        printf("multiplier must be > 1\n");
        return;
    }

    int i = 0;
    while (x > 0) {
        printf("<%d (%d)>\n", x, i);
        x = (int)((unsigned int)x * (unsigned int)a);
        i++;
    }
    printf("OVERFLOW [int]: <%d (%d)>\n", x, i);

    printf("%s() finish!\n", __func__);
}

void unsigned_int_input_processing() {
    printf("%s() start!\n", __func__);

    unsigned int x, prev;
    unsigned int a;
    printf("sizeof [unsigned int]: %zd\n", sizeof(x));
    printf("Enter an initial unsigned int: ");
    scanf_s("%u", &x);
    printf("Enter a multiplier (>1): ");
    scanf_s("%u", &a);
    if (a <= 1 || x == 0) {
        printf("need x > 0 and multiplier > 1\n");
        return;
    }

    int i = 0;
    do {
        printf("<%u (%d)>\n", x, i);
        prev = x;
        x *= a;
        i++;
    } while (x / a == prev);
    printf("OVERFLOW [unsigned int]: %u * %u = %u (%d)\n", prev, a, x, i);

    printf("%s() finish!\n", __func__);
}

void int_examples() {
    int_factorial_processing();
    int_input_processing();
    unsigned_int_input_processing();
}
