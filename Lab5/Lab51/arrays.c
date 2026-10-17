#include <stdio.h>
#include "examples.h"

void array_processing() {
    printf("%s() start!\n", __func__);

    int a[4];
    a[0] = 1;
    a[1] = 10;
    a[2] = 100;
    a[3] = 1000;

    printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);

    int b[5] = { 2, 20, 200, 2000, 20000 };
    printf("%d %d %d %d %d\n", b[0], b[1], b[2], b[3], b[4]);

    printf("%s() finish!\n", __func__);
}

void array_loop_processing() {
    printf("%s() start!\n", __func__);
    int a[4];
    a[0] = 1;
    a[1] = 10;
    a[2] = 100;
    a[3] = 1000;
    int i;
    i = 0;
    while (i < 4) {
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");
    int b[5] = { 2, 20, 200, 2000, 20000 };
    i = 0;
    while (i < 5) {
        printf("%d ", b[i]);
        i++;
    }
    printf("\n");
    printf("%s() finish!\n", __func__);
}

void array_loop_pointer_processing() {
    printf("%s() start!\n", __func__);

    int c[5];
    c[0] = 1;
    c[1] = 3;
    c[2] = 45;
    c[3] = 565;
    c[4] = 4552;
    
    int i = 0;
    while (i < 5) {
        printf("%d ", *(c + i++)); // указатель + оффсет
    }
    printf("\n");

    printf("%s() finish!\n", __func__);
}

void arrays_examples() {
    array_processing();
    array_loop_processing();
    array_loop_pointer_processing();
}
