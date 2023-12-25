#include "../include/noleaks.h"

static t_memory_block	*memory_block;
pthread_mutex_t			memory_list_lock = PTHREAD_MUTEX_INITIALIZER;
				// cannot be reallocated

void	*nlmalloc(size_t size)
{
	t_memory_block	*block;

	if (size == 0)
		return (NULL);
	pthread_mutex_lock(&memory_list_lock);
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
	pthread_mutex_unlock(&memory_list_lock);
	return (void *)(block + 1); // + for metadata
}

void	nlfree(void *ptr)
{
	t_memory_block	*block;

	if (!ptr)
		return ;
	pthread_mutex_lock(&memory_list_lock);
	block = (t_memory_block *)ptr - 1;
	block->free = 1;
	coalescence(&block);
	pthread_mutex_unlock(&memory_list_lock);
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

void check_fragmentation() {
    size_t free_blocks = 0;
    size_t used_blocks = 0;
    size_t total_free_size = 0;
    size_t total_used_size = 0;

    t_memory_block *current = memory_block;
    while (current != NULL) {
        if (current->free) {
            free_blocks++;
            total_free_size += current->size;
        } else {
            used_blocks++;
            total_used_size += current->size;
        }
        current = current->next;
    }

    ft_printf("Fragmentation Report:\n");
    ft_printf("Total free blocks: %d\n", (int)free_blocks);
    ft_printf("Total used blocks: %d\n", (int)used_blocks);
    ft_printf("Total free memory size: %d\n", (int)total_free_size);
    ft_printf("Total used memory size: %d\n", (int)total_used_size);
    ft_printf("Average free block size: %d\n", (int)free_blocks ? (int)total_free_size / (int)free_blocks : 0);
    ft_printf("Average used block size: %d\n", (int)used_blocks ? (int)total_used_size / (int)used_blocks : 0);
}
