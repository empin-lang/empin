#include <stdio.h>

#include "memory.h"
#include "value.h"

void EmpinValueArray_init(EmpinValueArray *self)
{
	self->values = NULL;
	self->capacity = 0;
	self->size = 0;
}

void EmpinValueArray_write(EmpinValueArray *self, EmpinValue value)
{
	if (self->capacity < self->size + 1)
	{
		epssize_t old_capacity = self->capacity;
		self->capacity = GROW_CAPACITY(old_capacity);
		self->values = GROW_ARRAY(EmpinValue, self->values,
			old_capacity, self->capacity);
	}
	self->values[self->size] = value;
	self->size ++;
}

void EmpinValueArray_destroy(EmpinValueArray *self)
{
	FREE_ARRAY(EmpinValue, self->values, self->capacity);
	EmpinValueArray_init(self);
}

void EmpinValue_print(EmpinValue *self)
{
	printf("%d", *self);
}
