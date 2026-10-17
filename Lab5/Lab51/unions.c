#include <stdio.h>
#include <stdint.h>
#include "examples.h"

union tag_var {
    char var_ch;
    int var_i;
    double var_d;
};

void union_processing() {
    union tag_var var;
    var.var_ch = 'C';
    var.var_i = 45;
}

union TestResult {
    int score;
    char grade;
};

void testresult_union_processing() {
    union TestResult me;

    me.score = 79;
    printf("My score: %d\n", me.score);

    me.grade = 'B';
    printf("My grade: %c\n", me.grade);

    printf("My score (again): %d\n", me.score);
}

union float_bits {
    float f;
    uint32_t u;
    unsigned char bytes[4];
};

void union_float_bits_processing() {
    printf("%s() start!\n", __func__);

    union float_bits fb;
    printf("sizeof [union float_bits]: %zd\n", sizeof(fb));
    printf("Enter a float: ");
    scanf_s("%f", &fb.f);

    printf("float = %f\n", fb.f);
    printf("same memory as uint32_t = 0x%08X\n", fb.u);
    printf("bytes in memory: %02X %02X %02X %02X\n", fb.bytes[0], fb.bytes[1], fb.bytes[2], fb.bytes[3]);

    unsigned sign = fb.u >> 31;
    unsigned exponent = (fb.u >> 23) & 0xFF;
    unsigned mantissa = fb.u & 0x7FFFFF;
    printf("sign = %u, exponent = %u (%d), mantissa = 0x%06X\n", sign, exponent, (int)exponent - 127, mantissa);

    printf("%s() finish!\n", __func__);
}

enum ValueType { V_INT, V_DOUBLE, V_TEXT };

struct Value {
    enum ValueType type;
    union {
        int i;
        double d;
        char text[16];
    };
};

static void print_value(struct Value v) {
    switch (v.type) {
    case V_INT:
        printf("int: %d\n", v.i);
        break;
    case V_DOUBLE:
        printf("double: %f\n", v.d);
        break;
    case V_TEXT:
        printf("text: %s\n", v.text);
        break;
    }
}

void tagged_union_processing() {
    printf("%s() start!\n", __func__);

    struct Value values[3];
    values[0].type = V_INT;
    values[0].i = 42;
    values[1].type = V_DOUBLE;
    values[1].d = 3.14;
    values[2].type = V_TEXT;
    snprintf(values[2].text, sizeof(values[2].text), "hello");

    for (int i = 0; i < 3; i++)
        print_value(values[i]);

    printf("sizeof [struct Value]: %zd\n", sizeof(struct Value));
    printf("sizeof if it were a struct: %zd\n", sizeof(enum ValueType) + sizeof(int) + sizeof(double) + 16);

    printf("%s() finish!\n", __func__);
}

void unions_examples() {
    union_processing();
    testresult_union_processing();
    union_float_bits_processing();
    tagged_union_processing();
}
