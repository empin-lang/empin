#include <stdio.h>

#include "debug.h"

static epssize_t simple_instruction(const char *name, epssize_t offset)
{
	printf("%s\n", name);
	return offset + 1;
}

void empin_disassemble_EmpinChunk(EmpinChunk *self, const char *name)
{
	printf("== %s == \n", name);

	for (epssize_t offset = 0;offset < self->size;)
	{
		offset = empin_disassemble_instruction(self, offset);
	}
}

epssize_t empin_disassemble_instruction(EmpinChunk *self, epssize_t offset)
{
	printf("%04lld ", offset);

	EmpinSlot instruction = self->code[offset];

	switch (instruction)
	{
		case OP_HALT:
			return simple_instruction("OP_HALT", offset);
		default:
			printf("Unknown opcode %u\n", instruction);
			return offset + 1;
	}
}
