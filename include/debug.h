#ifndef EMPIN_DEBUG_H
#define EMPIN_DEBUG_H

#include "chunk.h"

void empin_disassemble_EmpinChunk(EmpinChunk *self, const char *name);
EmpinSSize empin_disassemble_instruction(EmpinChunk *self, EmpinSSize offset);

#endif
