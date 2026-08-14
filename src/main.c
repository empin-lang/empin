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
	
	EmpinChunk_write_instruction(&chunk, OP_ADD, 0, 1, 2);
	EmpinChunk_write_instruction(&chunk, OP_HALT, NULL);
	empin_disassemble_EmpinChunk(&chunk, "test chunk");

	EmpinVM_destroy(&vm);
	EmpinChunk_destroy(&chunk);
	return 0;
}
