#include <stdio.h>
#include <math.h>
#include "examples.h"

void long_long_factorial_processing() {
    printf("%s() start!\n", __func__);

    int n = 1;
    long long fact = 1, prevFact = 1;

    while (n < 100) {
        fact = 1;
        int i = 1;
        do {
            fact = fact * i;
            i = i + 1;
        } while (i <= n);

        printf("<%lld (%d!) %d>\n", fact, n, (fact / prevFact));

        prevFact = fact;

        n += 1;
    }

    printf("%s() finish!\n", __func__);
}

void long_long_input_processing() {
    printf("%s() start!\n", __func__);

    long long x;
    long long a;
    printf("sizeof [long long]: %zd\n", sizeof(x));
    printf("Enter an initial long long: ");
    scanf_s("%lld", &x);
    printf("Enter a multiplier (>1): ");
    scanf_s("%lld", &a);
    if (a <= 1) {
        printf("multiplier must be > 1\n");
        return;
    }

    int i = 0;
    while (x > 0) {
        printf("<%lld (%d)>\n", x, i);
        x = (long long)((unsigned long long)x * (unsigned long long)a);
        i++;
    }
    printf("OVERFLOW [long long]: <%lld (%d)>\n", x, i);

    printf("%s() finish!\n", __func__);
}

void unsigned_long_long_processing() {
    printf("%s() start!\n", __func__);

    unsigned long long l = 1;
    printf("sizeof [unsigned long long]: %zd\n", sizeof(l));

    int i = 0;
    while (l > 0) {
        printf("<%llu (%d)>\n", l, i);
        l *= 2;
        i += 1;
    }
    l--;
    printf("OVERFLOW <!!!!%llu (%d)!!!!>\n", l, i);

    printf("%s() finish!\n", __func__);
}

void ull_input_processing() {
    printf("%s() start!\n", __func__);

    unsigned long long l;
    int a;
    printf("Enter an initial ULL: ");
    scanf_s("%llu", &l);
    printf("Enter an increment value: ");
    scanf_s("%d", &a);

    int i = 0;
    while (l > 0) {
        printf("<%llu (%d)>\n", l, (int)ceil(log2l(l)));
        l += a;
        i += 1;
    }
    printf("%d times to overflow initial ULL\n", i);

    printf("%s() finish!\n", __func__);
}

void long_long_examples() {
    long_long_factorial_processing();
    long_long_input_processing();
    unsigned_long_long_processing();
    ull_input_processing();
}
