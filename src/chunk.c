#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void EmpinChunk_init(EmpinChunk *self)
{
	self->size = 0;
	self->capacity = 0;
	self->code = NULL;
	EmpinValueArray_init(&self->constants);
}

void EmpinChunk_destroy(EmpinChunk *self)
{
	FREE_ARRAY(Slot, self->code, self->capacity);
	EmpinValueArray_destroy(&self->constants);
	EmpinChunk_init(self);
}

void EmpinChunk_write(EmpinChunk *self, Slot value)
{
	if (self->capacity < self->size + 1)
	{
		epssize_t old_capacity = self->capacity;
		self->capacity = GROW_CAPACITY(old_capacity);
		self->code = GROW_ARRAY(Slot, self->code, \
		old_capacity, self->capacity);
	}
	
	self->code[self->size] = value;
	self->size ++;
}

epssize_t EmpinChunk_add_constant(EmpinChunk *self, Value value)
{
	EmpinValueArray_write(&self->constants, value);
	return self->constants.size - 1;
}
