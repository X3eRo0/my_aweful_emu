#include "cpu.h"

void init_cpu(cpu * mycpu){

    mycpu->A = 0;
    mycpu->B = 0;
    mycpu->C = 0;
    mycpu->D = 0;
    mycpu->E = 0;
    mycpu->H = 0;
    mycpu->L = 0;
    mycpu->cf = 0;
    mycpu->zf = 0;
    mycpu->sp = 0;
    mycpu->pc = 0;

    mycpu->reg[0] = &mycpu->A;
    mycpu->reg[1] = &mycpu->B;
    mycpu->reg[2] = &mycpu->C;
    mycpu->reg[3] = &mycpu->D;
    mycpu->reg[4] = &mycpu->E;
    mycpu->reg[5] = &mycpu->H;
    mycpu->reg[6] = &mycpu->L;
    mycpu->reg[7] = &mycpu->cf;
    mycpu->reg[8] = &mycpu->zf;
    mycpu->reg[9] = &mycpu->sp;
    mycpu->reg[10] = &mycpu->pc;
    
    return;
}