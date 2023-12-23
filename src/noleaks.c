#include "../include/noleaks.h"

static t_memory_block	*memory_block;

void	*nlmalloc(size_t size)
{
	t_memory_block	*block;

	if (size == 0)
		return (NULL);
	size = align_size(size, STANDARD_ALIGNEMENT_UNIX);
	block = find_best_fit(size, &memory_block);
	if (!block)
	{
		block = mmap_alloc(size + sizeof(t_memory_block));
		if (!block)
			return (NULL);
		block->size = size;
		block->free = 0;
		block->next = NULL;
		block->before = find_last_block(memory_block);
		add_block_to_list(&memory_block, block);
	}
	else
	{
		if (block->size > size + sizeof(t_memory_block))
			spliting(block, size);
		block->free = 0;
	}
	return (void *)(block + 1); // + for metadata
}

void	nlfree(void *ptr)
{
	t_memory_block	*block;

	if (ptr == NULL)
		return ;
	block = (t_memory_block *)ptr - 1;
	block->free = 1;
	coalescence(&block);
}

void	check_memory_leaks(void)
{
	t_memory_block	*current;
	int				leaks_found;

	current = memory_block;
	leaks_found = 0;
	while (current != NULL)
	{
		if (!current->free)
		{
			ft_printf("Fuite -> adresse: %p taille: %d octets\n",
				(void *)(current + 1), (int)current->size);
			leaks_found += 1;
		}
		current = current->next;
	}
	if (!leaks_found)
		ft_printf("Aucune fuite de mémoire détectée. ✅\n");
	else
		ft_printf("%d fuite(s) detectées. 🆘\n", leaks_found);
}
