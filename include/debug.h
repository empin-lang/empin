#ifndef EMPIN_DEBUG_H
#define EMPIN_DEBUG_H

#include "chunk.h"

void disassemble_Chunk(Chunk *self, const char *name);
epssize_t disassemble_instruction(Chunk *self, epssize_t offset);

#endif
