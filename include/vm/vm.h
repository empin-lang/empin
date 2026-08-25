#ifndef EMPIN_VM_H
#define EMPIN_VM_H

#include "chunk.h"

#define EMP_REGISTER_COUNT 8
typedef EmpinValue EmpinReg;

typedef struct
{
 EmpinChunk *chunk;
 EmpinSlot *ip;
 EmpinReg regs[EMP_REGISTER_COUNT];
} EmpinVM;

void EmpinVM_init(EmpinVM *self);
void EmpinVM_destroy(EmpinVM *self);
int EmpinVM_interpret(EmpinVM *self, EmpinChunk *chunk);

#endif
