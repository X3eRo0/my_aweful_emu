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

    mycpu->reg[0] = (void *)&mycpu->A;
    mycpu->reg[1] = (void *)&mycpu->B;
    mycpu->reg[2] = (void *)&mycpu->C;
    mycpu->reg[3] = (void *)&mycpu->D;
    mycpu->reg[4] = (void *)&mycpu->E;
    mycpu->reg[5] = (void *)&mycpu->H;
    mycpu->reg[6] = (void *)&mycpu->L;
    mycpu->reg[7] = (void *)&mycpu->cf;
    mycpu->reg[8] = (void *)&mycpu->zf;
    mycpu->reg[9] = (void *)&mycpu->sp;
    mycpu->reg[10] = (void *)&mycpu->pc;

    mycpu->mem = (uint8_t *)malloc(sizeof(uint8_t) * MAX_MEM_SIZE);
    
    return;
}

void delete_cpu(cpu * mycpu){
    free(mycpu->mem);
    mycpu->mem = NULL;

    free(mycpu);
    mycpu = NULL;
    
    return;
}

void execute(cpu * mycpu){

    uint8_t opcode = mycpu->mem[mycpu->pc++];
    uint8_t arg_1  = mycpu->mem[mycpu->pc++];

    // 0x87, 0x50 <-- ADD A

    switch(opcode){
        case ADD_A:{
            mycpu->A += arg_1;
            break;
        }

        case SUB_A:{
            mycpu->A -= arg_1;
            break;
        }

        default:
            printf("Segmentation Fault XD\n");
            break;
    }

}