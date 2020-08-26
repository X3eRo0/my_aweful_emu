#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_MEM_SIZE 0x10000

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
    uint8_t isRunning;

} cpu;

void init_cpu(cpu *);
void delete_cpu(cpu *);
void execute(cpu *);
void print(char *, int);

#define ADD_A 0x87
#define ADD_B 0x80
#define SUB_A 0x97
#define SUB_B 0x90
#define MVI_A 0x3E
#define MVI_B 0x06
#define MVI_C 0x0E
#define LDA   0x3A
#define STA   0x32
#define HLT   0x76

#endif