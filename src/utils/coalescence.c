#include "../../include/noleaks.h"

void	coalescence(t_memory_block **memory_block)
{
	t_memory_block	*current;

	current = *memory_block;
	if (current->next && current->next->free)
	{
		current->size += current->next->size + sizeof(t_memory_block);
		if (current->next->next)
			current->next->next->before = current;
		current->next = current->next->next;
	}
	if (current->before && current->before->free)
	{
		current->before->size += current->size + sizeof(t_memory_block);
		current->before->next = current->next;
		if (current->next)
			current->next->before = current->before;
	}
}
