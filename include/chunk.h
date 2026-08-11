#ifndef EMPIN_CHUNK_H
#define EMPIN_CHUNK_H

#include "common.h"
#include "value.h"

typedef enum
{
 OP_HALT,
} EmpinOpCode;

typedef struct
{
 epssize_t size;
 epssize_t capacity;
 EmpinSlot *code;
 EmpinValueArray constants;
} EmpinChunk;
void EmpinChunk_init(EmpinChunk *self);
void EmpinChunk_destroy(EmpinChunk *self);
void EmpinChunk_write(EmpinChunk *self, EmpinSlot value);
epssize_t EmpinChunk_add_constant(EmpinChunk *chunk, EmpinValue value);

#endif
