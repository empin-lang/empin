#include <stdio.h>
#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, char *argv[])
{
	EmpinChunk chunk;
	EmpinChunk_init(&chunk);
	

	EmpinChunk_write(&chunk, OP_HALT);
	disassemble_EmpinChunk(&chunk, "test chunk");
	EmpinChunk_destroy(&chunk);
	return 0;
}
