#include "../../include/noleaks.h"

t_memory_block	*find_last_block(t_memory_block *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
