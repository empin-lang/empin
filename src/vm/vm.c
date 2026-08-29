#include "vm.h"
#include "common.h"
#include "ecall.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void EmpinVM_init(EmpinVM *self)
{
	memset(self->gprs, 0, sizeof(self->gprs));		
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

				self->gprs[rd] = (EmpinReg)((EmpinInt)self->gprs[rs1] +
				(EmpinInt)self->gprs[rs2]);
				break;
			case OP_ECALL:
				EmpinEcallNumber ecall = self->gprs[1];
				if (ecall == ECALL_PRINT_INT)
				{
					printf("%lld", self->gprs[1]);
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
