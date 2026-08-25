#ifndef EMPIN_VALUE_H
#define EMPIN_VALUE_H

#include "common.h"

typedef struct EmpinValue
{
 long long int i;
 unsigned long long int u;
 double d;
} EmpinValue;

typedef struct
{
	epssize_t capacity;
	epssize_t size;
	EmpinValue *values;
} EmpinValueArray;

void EmpinValueArray_init(EmpinValueArray *self);
void EmpinValueArray_write(EmpinValueArray *self, EmpinValue value);
void EmpinValueArray_destroy(EmpinValueArray *self);

void EmpinValue_print(EmpinValue *self);

#endif
