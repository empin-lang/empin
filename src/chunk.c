#include <stdlib.h>

#include "chunk.h"

void Chunk_init(Chunk *self)
{
	self->count = 0;
	self->capacity = 0;
	self->code = NULL;
}
