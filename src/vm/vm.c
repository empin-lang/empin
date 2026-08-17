#include "vm.h"
#include "common.h"
#include <stdbool.h>

void EmpinVM_init(EmpinVM *self)
{
	
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
			case OP_ADD:
				EmpinSlot rd = self->ip[1];
				self->ip ++;
				EmpinSlot rs1 = self->ip[2];
				self->ip ++;
				EmpinSlot rs2 = self->ip[3];

				self->regs[rd] = self->regs[rs1] +
				self->regs[rs2];
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
