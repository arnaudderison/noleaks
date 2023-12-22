#include "../../include/noleaks.h"

t_memory_block	*find_best_fit(size_t size, t_memory_block **memory_block)
{
	t_memory_block	*best_fit;
	t_memory_block	*current;

	best_fit = NULL;
	current = *memory_block;
	while (current != NULL)
	{
		if (current->free && current->size >= size)
		{
			if (best_fit == NULL || current->size < best_fit->size)
				best_fit = current;
		}
		current = current->next;
	}
	return (best_fit);
}
