#include <stdio.h>
#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, char *argv[])
{
	Chunk chunk;
	Chunk_init(&chunk);
	

	Chunk_write(&chunk, OP_RETURN);
	disassemble_Chunk(&chunk, "test chunk");
	Chunk_destroy(&chunk);
	return 0;
}
