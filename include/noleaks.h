#ifndef NOLEAKS_H
# define NOLEAKS_H
# define STANDARD_ALIGNEMENT_UNIX 8

# include "../src/libft/ft_printf/includes/ft_printf.h"
# include <fcntl.h>
# include <sys/mman.h> //mmap
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_memory_block	t_memory_block;
struct							s_memory_block
{
	size_t						size;
	int							free;
	t_memory_block				*next;
	t_memory_block				*before;
};

void							*mmap_alloc(size_t size);
void							coalescence(t_memory_block **memory_block);
t_memory_block					*find_best_fit(size_t size,
									t_memory_block **memory_block);
void							spliting(t_memory_block *memory_block,
									size_t size);
t_memory_block					*find_last_block(t_memory_block *list);
void							add_block_to_list(t_memory_block **list,
									t_memory_block *block);
size_t							align_size(size_t size, size_t alignment);
void							*nlmalloc(size_t size);
void							nlfree(void *ptr);
void							check_memory_leaks(void);
#endif
