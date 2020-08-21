#include "cpu.h"

int main(){

    cpu * mycpu = (cpu *)malloc(sizeof(cpu));
    init_cpu(mycpu);

    FILE * fp = fopen("instructions.bin", "r");
    fseek(fp, 0, SEEK_END);
    size_t file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fread(mycpu->mem, file_size, 1, fp);
    while(mycpu->isRunning){
        execute(mycpu);
        printf("A : 0x%x\n", mycpu->A );
        printf("B : 0x%x\n", mycpu->B );
        printf("C : 0x%x\n", mycpu->C );
        printf("D : 0x%x\n", mycpu->D );
        printf("E : 0x%x\n", mycpu->E );
        printf("H : 0x%x\n", mycpu->H );
        printf("L : 0x%x\n", mycpu->L );
        printf("sp: 0x%x\n", mycpu->sp);
        printf("pc: 0x%x\n", mycpu->pc);
        puts("=========");
    }
    delete_cpu(mycpu);
    return 0;
}

// MVI A, 50 -- 0x3e, 0x50
