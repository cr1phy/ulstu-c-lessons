#include <stdio.h>
#include "examples.h"

void implicit_cast_processing() {
    int val;
    val = 1 + 2.1;
    printf("val = %d", val);
}

void explicit_cast_processing() {
    int val;
    val = (int)(1 + 2.1);
    printf("val = %d", val);
}

void average_processing() {
    int sum = 0;
    float average;
    int grade;
    int counter = 0;

    do {
        scanf_s("%d", &grade);
        sum += grade;
        counter++;
    } while (grade != 0);

    average = (float)sum / (counter - 1);

    printf("average = %f", average);
}

void casts_examples() {
    implicit_cast_processing();
    explicit_cast_processing();
    average_processing();
}
