#include <stdlib.h>

#include "memory.h"

void *empin_reallocate(void *pointer, EmpinSSize old_size, EmpinSSize new_size)
{
	if (new_size == 0)
	{
		free(pointer);
		return NULL;
	}
	void *result = realloc(pointer, new_size);
	if (result == NULL) exit(1);
	return result;
}
