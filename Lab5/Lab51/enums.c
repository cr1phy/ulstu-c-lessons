#include <stdio.h>
#include "examples.h"

enum Modes {
    START,
    GAME,
    VICTORY,
    LOSS,
    FINAL
};

static enum Modes mode = START;

void enum_processing() {
    mode = (enum Modes)(mode + 1);
}

enum DayPhase {
    MORNING,
    DAY,
    EVENING,
    NIGHT
};

static const char* phase_name(enum DayPhase p) {
    switch (p) {
    case MORNING: return "morning";
    case DAY:     return "day";
    case EVENING: return "evening";
    case NIGHT:   return "night";
    }
    return "?";
}

static enum DayPhase phase_by_hour(int hour) {
    if (hour >= 6 && hour < 12)
        return MORNING;
    if (hour >= 12 && hour < 18)
        return DAY;
    if (hour >= 18 && hour < 23)
        return EVENING;
    return NIGHT;
}

void day_enum_processing() {
    printf("%s() start!\n", __func__);

    printf("sizeof [enum DayPhase]: %zd\n", sizeof(enum DayPhase));
    printf("MORNING=%d DAY=%d EVENING=%d NIGHT=%d\n", MORNING, DAY, EVENING, NIGHT);

    int hour;
    printf("Enter hour (0..23): ");
    scanf_s("%d", &hour);
    if (hour < 0 || hour > 23) {
        printf("hour must be 0..23\n");
        return;
    }

    enum DayPhase p = phase_by_hour(hour);
    printf("%02d:00 -> %s (%d)\n", hour, phase_name(p), p);

    printf("next phases:");
    for (int i = 0; i < 4; i++) {
        p = (enum DayPhase)((p + 1) % 4);
        printf(" %s", phase_name(p));
    }
    printf("\n");

    printf("%s() finish!\n", __func__);
}

void enums_examples() {
    enum_processing();
    day_enum_processing();
}
