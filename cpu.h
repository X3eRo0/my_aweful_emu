#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct _mycpu_ {

    uint8_t A;
    uint8_t B;
    uint8_t C;
    uint8_t D;
    uint8_t E;
    uint8_t H;
    uint8_t L;

    uint8_t reg[11];
    uint16_t sp;
    uint16_t pc;

    uint8_t zf;
    uint8_t cf;

} cpu;

#define ADD 0x1

#endif