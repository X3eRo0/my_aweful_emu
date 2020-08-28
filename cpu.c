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
    mycpu->sp = 0x7fff;
    mycpu->pc = 0;

    mycpu->mem = (uint8_t *)malloc(sizeof(uint8_t) * MAX_MEM_SIZE);
    mycpu->isRunning = 1;
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

    uint8_t  opcode = mycpu->mem[mycpu->pc++];
    uint8_t  arg_1  = 0;
    uint16_t imm_v  = 0;

    // 0x87, 0x50 <-- ADD A

    switch(opcode){
        case ADD_A:{
            mycpu->A += mycpu->A;
            break;
        }

        case ADD_B:{
            mycpu->A += mycpu->B;
            break;
        }

        case SUB_A:{
            mycpu->A -= mycpu->A;
            break;
        }
    
        case SUB_B:{
            mycpu->A -= mycpu->B;
            break;
        }

        case MVI_A:{
            arg_1 = mycpu->mem[mycpu->pc++];
            mycpu->A = arg_1;
            break;
        }

        case MVI_B:{
            arg_1 = mycpu->mem[mycpu->pc++];
            mycpu->B = arg_1;
            break;
        }

        case MVI_C:{
            arg_1 = mycpu->mem[mycpu->pc++];
            mycpu->C = arg_1;
            break;
        }

        case MVI_D:{
            arg_1 = mycpu->mem[mycpu->pc++];
            mycpu->D = arg_1;
            break;
        }
    
        case MVI_H:{
            arg_1 = mycpu->mem[mycpu->pc++];
            mycpu->H = arg_1;
            break;
        }

        case LDA:{
            imm_v = *(uint16_t *)((uint8_t *)mycpu->mem + mycpu->pc);
            mycpu->pc += 2;
            mycpu->A = mycpu->mem[imm_v];

            break;
        }

        case STA:{
            imm_v = *(uint16_t *)((uint8_t *)mycpu->mem + mycpu->pc);
            mycpu->pc += 2;
            mycpu->mem[imm_v] = mycpu->A;
            break;
        }

        case PUSH_B:{
            mycpu->mem[mycpu->sp++] = mycpu->B;
            break;
        }


        case PUSH_D:{
            mycpu->mem[mycpu->sp++] = mycpu->D;
            break;
        }


        case PUSH_H:{
            mycpu->mem[mycpu->sp++] = mycpu->H;
            break;
        }

        case POP_B:{
            mycpu->B = mycpu->mem[--mycpu->sp];
            break;
        }
    
        case POP_D:{
            mycpu->D = mycpu->mem[--mycpu->sp];
            break;
        }

        case POP_H:{
            mycpu->H = mycpu->mem[--mycpu->sp];
            break;
        }

        case HLT:{
            mycpu->isRunning = 0;
            break;
        }

        default:
            printf("Segmentation Fault XD\n");
            mycpu->isRunning = 0;
            break;
    }

}

void print(char * mem, int len){
    for (int i = 0; i < len; i++){
        printf("%.2X ", (uint8_t)mem[i]);
    }
    puts("");
}