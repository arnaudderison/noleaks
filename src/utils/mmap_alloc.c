#include "../../include/noleaks.h"

void	*mmap_alloc(size_t size)
{
	int		fd;
	void	*memory;

	fd = open("/dev/zero", O_RDWR); // replace MAP_ANNONYME
	memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);
	return (memory);
}
