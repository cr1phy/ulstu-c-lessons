#include <stdio.h>
#include "examples.h"

struct date { int d, m, y; };

void struct_processing() {
    printf("%s() start!\n", __func__);

    struct date d1;
    d1.d = 11;
    d1.m = 3;
    d1.y = 2022;

    struct date d2 = { 31, 12, 2021 };

    printf("(%02d.%02d.%d)\n", d1.d, d1.m, d1.y);
    printf("(%02d.%02d.%d)\n", d2.d, d2.m, d2.y);

    printf("%s() finish!\n", __func__);
}

struct user { int id; char* name; struct date date_of_birth; };

void user_struct_processing() {
    printf("%s() start!\n", __func__);
    
    struct date birthday = { 12, 9, 1993 };
    struct user bob = { 1, "Bob", birthday };
    printf("Hey, %s! Your birthday on %02d/%02d/%d.\n", bob.name, bob.date_of_birth.m, bob.date_of_birth.d, bob.date_of_birth.y);
    
    printf("%s() finish!\n", __func__);
}

void structs_examples() {
    struct_processing();
    user_struct_processing();
}
