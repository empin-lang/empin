#ifndef EMPIN_MEMORY_H
#define EMPIN_MEMORY_H

#include "common.h"

#define GROW_ARRAY(type, pointer, old_size, new_size) \
	(type*)reallocate(pointer, sizeof(type) * (old_size), \
		sizeof(type) * (new_size))

#define FREE_ARRAY(type, pointer, old_size) \
	reallocate(pointer, sizeof(type) * old_size, 0);

void *reallocate(void *pointer, epssize_t old_size, epssize_t new_size);

#endif
