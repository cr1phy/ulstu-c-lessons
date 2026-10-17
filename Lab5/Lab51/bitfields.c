#include <stdio.h>
#include <stdint.h>
#include "examples.h"

struct date_time {
    unsigned day : 5;
    unsigned month : 4;
    unsigned year : 12;
    unsigned sec : 6;
    unsigned min : 6;
    unsigned hour : 5;
};

void bitfield_processing() {
    struct date_time dt = { 3, 5, 2023, 11, 7, 10 };
    printf("%02d/%02d/%d %02d:%02d:%02d\n", dt.day, dt.month, dt.year, dt.hour, dt.min, dt.sec);
}

typedef union {
    uint8_t reg_val;
    struct {
        uint8_t clipping_information : 1;
        uint8_t output_offset_information : 1;
        uint8_t input_offset_information : 1;
        uint8_t fault_information : 1;
        uint8_t temperature_warning_information : 3;
        uint8_t res : 1;
    };
} Fda801RegIb2Addr_t;

void bitfield_union_processing() {
    uint8_t reg_val = 0;
    Fda801RegIb2Addr_t Reg;
    Reg.reg_val = reg_val;
}

struct permissions {
    unsigned other : 3;
    unsigned group : 3;
    unsigned owner : 3;
};

struct permissions_plain {
    unsigned other;
    unsigned group;
    unsigned owner;
};

static void print_rwx(unsigned bits) {
    printf("%c%c%c",
        (bits & 4) ? 'r' : '-',
        (bits & 2) ? 'w' : '-',
        (bits & 1) ? 'x' : '-');
}

void permissions_bitfield_processing() {
    printf("%s() start!\n", __func__);

    unsigned mode;
    printf("Enter permissions in octal (e.g. 755): ");
    scanf_s("%o", &mode);

    struct permissions p;
    p.owner = (mode >> 6) & 7;
    p.group = (mode >> 3) & 7;
    p.other = mode & 7;

    printf("%o -> ", mode);
    print_rwx(p.owner);
    print_rwx(p.group);
    print_rwx(p.other);
    printf("\n");

    printf("sizeof [bitfield struct]: %zd\n", sizeof(struct permissions));
    printf("sizeof [plain struct]:    %zd\n", sizeof(struct permissions_plain));

    p.owner = 9;
    printf("OVERFLOW [3-bit field]: 9 -> %u\n", p.owner);

    printf("%s() finish!\n", __func__);
}

void bitfields_examples() {
    bitfield_processing();
    permissions_bitfield_processing();
    bitfield_union_processing();
}
