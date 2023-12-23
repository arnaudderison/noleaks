#include "../../include/noleaks.h"

void	add_block_to_list(t_memory_block **list, t_memory_block *block)
{
	t_memory_block	*last;

	if (!*list)
		*list = block;
	else
	{
		last = find_last_block(*list);
		last->next = block;
		block->before = last;
	}
}
