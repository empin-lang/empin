#ifndef EMPIN_VM_H
#define EMPIN_VM_H

#include "chunk.h"

typedef struct
{
 EmpinChunk *chunk;
} EmpinVM;

void EmpinVM_init(EmpinVM *self);
void EmpinVM_destroy(EmpinVM *self);

#endif
