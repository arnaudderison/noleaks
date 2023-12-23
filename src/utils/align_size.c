#include "../../include/noleaks.h"

size_t	align_size(size_t size, size_t alignment)
{
	size_t	remainder;

	if (alignment == 0)
		return (size);
	remainder = size % alignment;
	if (remainder == 0)
		return (size);
	return (size + alignment - remainder);
}
