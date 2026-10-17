#include <stdio.h>
#include "examples.h"

void pointer_processing() {
    printf("%s() start!\n", __func__);

    int a;
    int* pa;

    a = 10;
    pa = &a;

    printf("val: a=%d *pa=%d pa=%p\n", a, *pa, pa);
    printf("ptr: &a=%p &pa=%p\n", &a, &pa);
    printf("sizeof: %zd %zd\n", sizeof a, sizeof(pa));

    *pa = 30;

    printf("val: a=%d *pa=%d pa=%p\n", a, *pa, pa);

    printf("%s() finish!\n", __func__);
}

static void f(int* ps, int a, int b) {
    *ps = a + b;
}

void pointer_arg_processing() {
    printf("%s() start!\n", __func__);

    int i1, i2, i3;

    i1 = 10;
    i2 = 20;
    i3 = 30;

    printf("i1=%d i2=%d i3=%d\n", i1, i2, i3);

    f(&i1, i2, i3);

    printf("i1=%d i2=%d i3=%d\n", i1, i2, i3);

    printf("%s() finish!\n", __func__);
}

static int add(int x, int y) {
    return x + y;
}

void funcptr_processing() {
    printf("%s() start!\n", __func__);

    int a, b;
    printf("Enter two numbers: ");
    scanf_s("%d%d", &a, &b);
    int (*op)(int, int) = add;
    printf("result=%d funcptr_op=%p\n", op(a, b), op);
    printf("sizeof result=%zd\n", sizeof(op(a, b)));
    printf("sizeof funcptr_op=%zd\n", sizeof op);

    printf("%s() finish!\n", __func__);
}

void pointers_examples() {
    pointer_processing();
    pointer_arg_processing();
    funcptr_processing();
}
