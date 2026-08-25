#include "vm.h"
#include "common.h"
#include "ecall.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void EmpinVM_init(EmpinVM *self)
{
	memset(self->regs, 0, sizeof(self->regs));	
}

void EmpinVM_destroy(EmpinVM *self)
{

}

static int EmpinVM_run(EmpinVM *self)
{
	while (true)
	{
		EmpinSlot instruction = self->ip[0];
		switch (instruction)
		{
			case OP_HALT:
				return 0;
			case OP_ADD_I:
				EmpinSlot rd = self->ip[1];
				EmpinSlot rs1 = self->ip[2];
				EmpinSlot rs2 = self->ip[3];

				self->regs[rd].i = self->regs[rs1].i +
				self->regs[rs2].i;
				break;
			case OP_ECALL:
				EmpinEcallNumber ecall = self->regs[0].i;
				if (ecall == ECALL_PRINT_INT)
				{
					printf("%lld", self->regs[1].i);
				}
				break;
		}
		self->ip += EMP_INSTRUCTION_SIZE;
	}
}

int EmpinVM_interpret(EmpinVM *self, EmpinChunk *chunk)
{
	self->chunk = chunk;
	self->ip = self->chunk->code;
	return EmpinVM_run(self);
}
