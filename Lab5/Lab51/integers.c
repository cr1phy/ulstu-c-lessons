#include <stdio.h>
#include <math.h>
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

void integers_examples() {
    char_processing();
    char_factorial();
    char_input_processing();
    unsigned_char_input_processing();
    short_processing();
    short_factorial_processing();
    short_input_processing();
    unsigned_short_input_processing();
    int_factorial_processing();
    int_input_processing();
    unsigned_int_input_processing();
    long_factorial_processing();
    long_input_processing();
    long_long_factorial_processing();
    long_long_input_processing();
    unsigned_long_long_processing();
    ull_input_processing();
}
