#include "cpu.h"

int main(){

    cpu * mycpu = (cpu *)malloc(sizeof(cpu));
    init_cpu(mycpu);

    FILE * fp = fopen("instruction.bin", "r");
    fseek(fp, 0, SEEK_END);
    size_t file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fread(mycpu->mem, file_size, 1, fp);
    printf("A: 0x%x\n", mycpu->A);
    execute(mycpu);
    printf("A: 0x%x\n", mycpu->A);
    execute(mycpu);
    printf("A: 0x%x\n", mycpu->A);
    delete_cpu(mycpu);
    return 0;
}