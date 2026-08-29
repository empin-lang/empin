#ifndef EMPIN_VALUE_H
#define EMPIN_VALUE_H

#include "common.h"

typedef struct EmpinValue
{
 EmpinInt i;
 EmpinUint u;
 EmpinFloat d;
} EmpinValue;

typedef struct
{
	EmpinSSize capacity;
	EmpinSSize size;
	EmpinValue *values;
} EmpinValueArray;

void EmpinValueArray_init(EmpinValueArray *self);
void EmpinValueArray_write(EmpinValueArray *self, EmpinValue value);
void EmpinValueArray_destroy(EmpinValueArray *self);

void EmpinValue_print(EmpinValue *self);

#endif
