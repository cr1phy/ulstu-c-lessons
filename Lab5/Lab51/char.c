#include <stdio.h>
#include "examples.h"

void char_processing() {
    printf("%s() start!\n", __func__);

    // Зависит от компилятора, но по дефолту char = signed char
    // https://stackoverflow.com/questions/2054939/is-char-signed-or-unsigned-by-default
    char c = 's';
    printf("sizeof [char]: %zd\n", sizeof(c));
    printf("numeric value of `%c` = %hhi\n", c, c);

    // Строгий знаковый char
    signed char sc = 1;
    int is = 0;
    while (sc > 0) {
        printf("<%d (%d)>\n", sc, is);
        sc *= 2;
        is += 1;
    }
    printf("OVERFLOW [signed char]: <%d (%d)>\n", sc, is);

    // Строгий беззнаковый char
    unsigned char usc = 1;
    int ius = 0;
    while (usc > 0) {
        printf("<%d (%d)>\n", usc, ius);
        usc *= 2;
        ius += 1;
    }
    printf("OVERFLOW [unsigned char]: <%d (%d)>\n", usc, ius);

    printf("%s() finish!\n", __func__);
}

void char_factorial() {
    printf("%s() start!\n", __func__);

    int n = 1;
    char fact = 1, prevFact = 1;

    while (n < 100) {
        fact = 1;
        int i = 1;
        do {
            fact *= i;
            i++;
        } while (i <= n);

        printf("<%hhi (%d!) %d>\n", fact, n, (fact / prevFact));

        prevFact = fact;

        n += 1;
    }

    printf("%s() finish!\n", __func__);
}

void char_input_processing() {
    printf("%s() start!\n", __func__);

    signed char c;
    int a;
    printf("sizeof [signed char]: %zd\n", sizeof(c));
    printf("Enter an initial signed char (-128..127): ");
    scanf_s("%hhd", &c);
    printf("Enter an increment value (>0): ");
    scanf_s("%d", &a);
    if (a <= 0) {
        printf("increment must be > 0\n");
        return;
    }

    int i = 0;
    while (c >= 0) {
        printf("<%hhd (%d)>\n", c, i);
        c = (signed char)(c + a);
        i++;
    }
    printf("OVERFLOW [signed char]: <%hhd (%d)>\n", c, i);

    printf("%s() finish!\n", __func__);
}

void unsigned_char_input_processing() {
    printf("%s() start!\n", __func__);

    unsigned char c, prev;
    int a;
    printf("sizeof [unsigned char]: %zd\n", sizeof(c));
    printf("Enter an initial unsigned char (0..255): ");
    scanf_s("%hhu", &c);
    printf("Enter an increment value (>0): ");
    scanf_s("%d", &a);
    if (a <= 0) {
        printf("increment must be > 0\n");
        return;
    }

    int i = 0;
    do {
        printf("<%hhu (%d)>\n", c, i);
        prev = c;
        c = (unsigned char)(c + a);
        i++;
    } while (c > prev);
    printf("OVERFLOW [unsigned char]: %hhu -> %hhu (%d)\n", prev, c, i);

    printf("%s() finish!\n", __func__);
}

void char_examples() {
    char_processing();
    char_factorial();
    char_input_processing();
    unsigned_char_input_processing();
}
