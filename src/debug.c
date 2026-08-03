#include <stdio.h>

#include "debug.h"

static size_t simple_instruction(const char *name, size_t offset)
{
	printf("%s\n", name);
	return offset + 1;
}

void disassemble_Chunk(Chunk *self, const char *name)
{
	printf("== %s == \n", name);

	for (size_t offset = 0;offset < self->size;)
	{
		offset = disassemble_instruction(self, offset);
	}
}

size_t disassemble_instruction(Chunk *self, size_t offset)
{
	printf("%04zu ", offset);

	Slot instruction = self->code[offset];

	switch (instruction)
	{
		case OP_RETURN:
			return simple_instruction("OP_RETURN", offset);
		default:
			printf("Unknown opcode %u\n", instruction);
			return offset + 1;
	}
}
