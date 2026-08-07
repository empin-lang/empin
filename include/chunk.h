#ifndef EMPIN_CHUNK_H
#define EMPIN_CHUNK_H

#include "common.h"

typedef enum
{
 OP_HALT,
} OpCode;

typedef struct
{
 epssize_t size;
 epssize_t capacity;
 Slot *code;
} Chunk;
void Chunk_init(Chunk *self);
void Chunk_destroy(Chunk *self);
void Chunk_write(Chunk *self, Slot value);

#endif
