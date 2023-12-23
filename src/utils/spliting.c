#include "../../include/noleaks.h"

void	spliting(t_memory_block *memory_block, size_t size)
{
	t_memory_block	*new_block;

	new_block = (t_memory_block *)((char *)memory_block + size
		+ sizeof(t_memory_block)); // new adress for new_block
	new_block->size = memory_block->size - size - sizeof(t_memory_block);
	new_block->free = 1;
	new_block->next = memory_block->next;
	new_block->before = memory_block;
	memory_block->size = size;
	memory_block->next = new_block;
	if (new_block->next)
	{
		new_block->next->before = new_block;
	}
}
