#include <stdio.h>
#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, char *argv[])
{
	EmpinVM vm;
	EmpinVM_init(&vm);
	
	EmpinChunk chunk;
	EmpinChunk_init(&chunk);

	EmpinChunk_write_instruction(&chunk, OP_LDI_I, 1, 2);
	EmpinChunk_write_instruction(&chunk, OP_LDI_I, 2, 3);	
	EmpinChunk_write_instruction(&chunk, OP_ADD_I, 1, 1, 2);
	EmpinChunk_write_instruction(&chunk, OP_ECALL);
	EmpinChunk_write_instruction(&chunk, OP_HALT, NULL);
	printf("\nexit(%d)\n", EmpinVM_interpret(&vm, &chunk));
	
	empin_disassemble_EmpinChunk(&chunk, "test chunk");

	EmpinVM_destroy(&vm);
	EmpinChunk_destroy(&chunk);
	return 0;
}
