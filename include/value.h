#ifndef EMPIN_VALUE_H
#define EMPIN_VALUE_H

#include "common.h"

typedef int EmpinValue;

typedef struct
{
	epssize_t capacity;
	epssize_t size;
	EmpinValue *values;
} EmpinValueArray;

void EmpinValueArray_init(EmpinValueArray *self);
void EmpinValueArray_write(EmpinValueArray *self, EmpinValue value);
void EmpinValueArray_destroy(EmpinValueArray *self);


#endif
