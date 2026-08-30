#include <stdlib.h>
#include <stdarg.h>

#include "common.h"
#include "chunk.h"
#include "memory.h"

void EmpinChunk_init(EmpinChunk *self)
{
	self->size = 0;
	self->capacity = 0;
	self->code = NULL;
	EmpinValueArray_init(&self->constants);
}

void EmpinChunk_destroy(EmpinChunk *self)
{
	FREE_ARRAY(EmpinSlot, self->code, self->capacity);
	EmpinValueArray_destroy(&self->constants);
	EmpinChunk_init(self);
}

void EmpinChunk_write(EmpinChunk *self, EmpinSlot value)
{
	if (self->capacity < self->size + 1)
	{
		EmpinSSize old_capacity = self->capacity;
		self->capacity = GROW_CAPACITY(old_capacity);
		self->code = GROW_ARRAY(EmpinSlot, self->code, \
		old_capacity, self->capacity);
	}
	
	self->code[self->size] = value;
	self->size ++;
}

EmpinSSize EmpinChunk_add_constant(EmpinChunk *self, EmpinValue value)
{
	EmpinValueArray_write(&self->constants, value);
	return self->constants.size - 1;
}

void EmpinChunk_write_instruction(EmpinChunk *self, EmpinOpCode op, ...)
{
	va_list args;
	va_start(args, op);

	EmpinChunk_write(self, (EmpinSlot)op);
	
	switch (op)
	{
		case OP_HALT:
		{
			EmpinChunk_write(self, 0);
			EmpinChunk_write(self, 0);
			EmpinChunk_write(self, 0);
			break;
		}
		case OP_ADD_I:
		{
			EmpinSlot rd = (EmpinSlot)(va_arg(args, int));
			EmpinSlot rs1 = (EmpinSlot)(va_arg(args, int));
			EmpinSlot rs2 = (EmpinSlot)(va_arg(args, int));

			EmpinChunk_write(self, rd);
			EmpinChunk_write(self, rs1);
			EmpinChunk_write(self, rs2);
			break;
		}
		case OP_LDI_I:
		{
			EmpinSlot rd = (EmpinSlot)(va_arg(args, int));
			short int value = (short int)(va_arg(args, int));
			EmpinSlot low = (EmpinSlot)(value & 0xFF);
			EmpinSlot high = (EmpinSlot)((value >> EMP_SLOT_WIDTH) & 0xFF);
			EmpinChunk_write(self, rd);
			EmpinChunk_write(self, low);
			EmpinChunk_write(self, high);
			break;
		}
		case OP_ECALL:
		{
			EmpinChunk_write(self, 0);
			EmpinChunk_write(self, 0);
			EmpinChunk_write(self, 0);
			break;
		}	
	}
	va_end(args);	
}
