#ifndef EMPIN_VALUE_H
#define EMPIN_VALUE_H

#include "common.h"

typedef int Value;

typedef struct
{
	epssize_t capacity;
	epssize_t size;
	Value *values;
} EmpinValueArray;

void EmpinValueArray_init(EmpinValueArray *self);
void EmpinValueArray_write(EmpinValueArray *self, Value value);
void EmpinValueArray_destroy(EmpinValueArray *self);


#endif
