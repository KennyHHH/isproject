#include "mm.h"
#include <stdio.h>
#include <stdlib.h>

struct Block {
	int block_size;
	struct Block *next_block;
};
const int overhead = sizeof(struct Block);
const int voidsize = sizeof(void*);

int main()
{
	int x = overhead + voidsize;
    return 0;
}

