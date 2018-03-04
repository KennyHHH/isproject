#include "mm.h"
#include <stdio.h>
#include <stdlib.h>

struct Block {
	int block_size;
	struct Block *next_block;
};
const int overhead = sizeof(struct Block);
const int voidsize = sizeof(void*);

struct Block *free_head;

void my_initialize_heap(int size) {
	struct Block *a;
	a = (struct Block *)malloc(size - overhead);
	free_head = a;
	free_head->block_size = size - overhead;
	free_head->next_block = free_head;

}
void* my_alloc(int size) {

}


int main()
{
	int x = overhead + voidsize;
	return 0;
}

