#include <stdio.h>
#include "examples.h"

void short_processing() {
    printf("%s() start!\n", __func__);

    short s = 1;
    int i = 0;
    while (s > 0) {
        printf("<%d (%d)>\n", s, i);
        s *= 2;
        i += 1;
    }
    s--;
    printf("<!!!!%d (%d)!!!!>\n", s, i);

    printf("%s() finish!\n", __func__);
}

void short_factorial_processing() {
    printf("%s() start!\n", __func__);

    int n = 1;
    short fact = 1, prevFact = 1;

    while (n < 100) {
        fact = 1;
        int i = 1;
        do {
            fact = fact * i;
            i = i + 1;
        } while (i <= n);

        printf("<%hi (%d!) %d>\n", fact, n, (fact / prevFact));

        prevFact = fact;

        n += 1;
    }

    printf("%s() finish!\n", __func__);
}

void short_input_processing() {
    printf("%s() start!\n", __func__);

    short s;
    int a;
    printf("sizeof [short]: %zd\n", sizeof(s));
    printf("Enter an initial short (-32768..32767): ");
    scanf_s("%hd", &s);
    printf("Enter an increment value (>0): ");
    scanf_s("%d", &a);
    if (a <= 0) {
        printf("increment must be > 0\n");
        return;
    }

    int i = 0;
    while (s >= 0) {
        printf("<%hd (%d)>\n", s, i);
        s = (short)(s + a);
        i++;
    }
    printf("OVERFLOW [short]: <%hd (%d)>\n", s, i);

    printf("%s() finish!\n", __func__);
}

void unsigned_short_input_processing() {
    printf("%s() start!\n", __func__);

    unsigned short s, prev;
    int a;
    printf("sizeof [unsigned short]: %zd\n", sizeof(s));
    printf("Enter an initial unsigned short (0..65535): ");
    scanf_s("%hu", &s);
    printf("Enter an increment value (>0): ");
    scanf_s("%d", &a);
    if (a <= 0) {
        printf("increment must be > 0\n");
        return;
    }

    int i = 0;
    do {
        printf("<%hu (%d)>\n", s, i);
        prev = s;
        s = (unsigned short)(s + a);
        i++;
    } while (s > prev);
    printf("OVERFLOW [unsigned short]: %hu -> %hu (%d)\n", prev, s, i);

    printf("%s() finish!\n", __func__);
}

void short_examples() {
    short_processing();
    short_factorial_processing();
    short_input_processing();
    unsigned_short_input_processing();
}
