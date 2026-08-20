#include <stdio.h>

#include "debug.h"

static epssize_t simple_instruction(const char *name, epssize_t offset)
{
	printf("%s\n", name);
	return offset + EMP_INSTRUCTION_SIZE;
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
		case OP_ADD:
			EmpinSlot rd = self->code[offset + 1],
			 rs1 = self->code[offset + 2],
			 rs2 = self->code[offset + 3];
			printf("%s R%d, R%d, R%d\n", "OP_ADD", rd, rs1, rs2);
			return offset + EMP_INSTRUCTION_SIZE;
		case OP_ECALL:
			return simple_instruction("OP_ECALL", offset);	
		default:
			printf("Unknown opcode %u\n", instruction);
			return offset + EMP_INSTRUCTION_SIZE;
	}
}
