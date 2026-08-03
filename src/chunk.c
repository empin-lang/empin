#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void Chunk_init(Chunk *self)
{
	self->size = 0;
	self->capacity = 10;
	self->code = malloc(10 * sizeof(Slot));
}

void Chunk_destroy(Chunk *self)
{
	FREE_ARRAY(Slot, self->code, self->capacity);
	Chunk_init(self);
}

void Chunk_write(Chunk *self, Slot value)
{
	if (self->capacity < self->size + 1)
	{
		size_t old_capacity = self->capacity;
		self->capacity = old_capacity * 2;
		self->code = GROW_ARRAY(Slot, self->code, \
		old_capacity, self->capacity);
	}
	
	self->code[self->size] = value;
	self->size ++;
}
