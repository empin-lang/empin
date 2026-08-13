#include <stdio.h>
#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, char *argv[])
{
	EmpinChunk chunk;
	EmpinChunk_init(&chunk);
	
	EmpinChunk_write_instruction(&chunk, OP_ADD, 0, 1, 2);
	EmpinChunk_write_instruction(&chunk, OP_HALT, NULL);
	empin_disassemble_EmpinChunk(&chunk, "test chunk");
	EmpinChunk_destroy(&chunk);
	return 0;
}
