#ifndef NOLEAKS_H
# define NOLEAKS_H

# include <unistd.h>

typedef struct
{
	size_t	size;
	int		free;
}			memory_block;
#endif
