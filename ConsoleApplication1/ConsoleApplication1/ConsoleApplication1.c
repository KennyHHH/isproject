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
	a = (struct Block *)malloc(size);
	free_head = a;
	free_head->block_size = size - overhead;
	free_head->next_block = NULL;

}
void* my_alloc(int size) {
	if (free_head != NULL) {
		struct Block *current = free_head;
		struct Block *previous = NULL;

		while (current->block_size < size && current->next_block != NULL) {
			current = current->next_block;
		}
		if (current->block_size > (size + overhead + voidsize)) {
			struct Block* NewBlock =(struct Block*)((void*) current) + size + overhead + voidsize;
			NewBlock->next_block = current->next_block;
			NewBlock->block_size = current->block_size-size-overhead-voidsize;
			current->block_size = size;
			free_head = NewBlock;

		}

	}
}


int main()
{
	int x = overhead + voidsize;
	return 0;
}

