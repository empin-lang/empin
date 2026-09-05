#include <stdio.h>

#include "debug.h"

static EmpinSSize simple_instruction(const char *name, EmpinSSize offset)
{
	printf("%s\n", name);
	return offset + EMP_INSTRUCTION_SIZE;
}

void empin_disassemble_EmpinChunk(EmpinChunk *self, const char *name)
{
	printf("== %s == \n", name);

	for (EmpinSSize offset = 0;offset < self->size;)
	{
		offset = empin_disassemble_instruction(self, offset);
	}
}

EmpinSSize empin_disassemble_instruction(EmpinChunk *self, EmpinSSize offset)
{
	printf("%04lld ", offset);

	EmpinSlot instruction = self->code[offset];

	switch (instruction)
	{
		case OP_HALT:
		{
			return simple_instruction("OP_HALT", offset);
		}
		case OP_ADD_I:
		{
			EmpinSlot rd = self->code[offset + 1],
			 rs1 = self->code[offset + 2],
			 rs2 = self->code[offset + 3];
			printf("%s R%d, R%d, R%d\n", "OP_ADD_I", rd, rs1, rs2);
			return offset + EMP_INSTRUCTION_SIZE;
		}
		case OP_LDI_I:
		{
			EmpinSlot rd = self->code[offset + 1];
			short int value = (short int)((self->code[offset + 3] >> EMP_SLOT_WIDTH) | self->code[offset + 2]);
			printf("%s R%d %d\n", "OP_LDI_I", rd, value);
			return offset + EMP_INSTRUCTION_SIZE;
		}
		case OP_BEQ:
		{
			EmpinSlot rs1 = self->code[offset + 1];
			EmpinSlot rs2 = self->code[offset + 2];
			EmpinSlot off = self->code[offset + 3];
			printf("%s R%d R%d %d\n", "OP_BEQ", rs1, rs2, off);
			return offset + EMP_INSTRUCTION_SIZE;
		}
		case OP_ECALL:
		{
			return simple_instruction("OP_ECALL", offset);
		}
		default:
		{
			printf("Unknown opcode %u\n", instruction);
			return offset + EMP_INSTRUCTION_SIZE;
		}
	}
}
