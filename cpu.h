#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_MEM_SIZE 0x1000

typedef struct _mycpu_ {

    uint8_t A;
    uint8_t B;
    uint8_t C;
    uint8_t D;
    uint8_t E;
    uint8_t H;
    uint8_t L;

    void * reg[11];
    uint16_t sp;
    uint16_t pc;

    uint8_t zf;
    uint8_t cf;

    uint8_t * mem;

} cpu;

void init_cpu(cpu *);
void delete_cpu(cpu *);
void execute(cpu *);

#define ADD_A 0x87
#define SUB_A 0x97

#endif