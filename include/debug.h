#ifndef EMPIN_DEBUG_H
#define EMPIN_DEBUG_H

#include "chunk.h"

void disassemble_Chunk(Chunk *self, const char *name);
size_t disassemble_instruction(Chunk *self, size_t offset);

#endif
