#ifndef CHUNK_H
#define CHUNK_H

#include "common.h"

typedef enum
{
 OP_RETURN,
} OpCode;

typedef struct
{
 size_t count;
 size_t capacity;
 short int *code;
} Chunk;
void Chunk_init(Chunk *self);

#endif
