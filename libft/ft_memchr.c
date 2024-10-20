#include <stddef.h>    // For size_t

void       *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	i = 0;
	const char *pointer;
	pointer = s;
	while (i < n)
	{
		if (pointer[i] == c)
			return (void *)pointer + i;
		i++;
	}
	return NULL;
}