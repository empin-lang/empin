#ifndef EMPIN_DEBUG_H
#define EMPIN_DEBUG_H

#include "chunk.h"

void disassemble_EmpinChunk(EmpinChunk *self, const char *name);
epssize_t disassemble_instruction(EmpinChunk *self, epssize_t offset);

#endif
