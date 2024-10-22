#include <stddef.h>    // For size_t

void       *ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;
 unsigned char *dst_char;
 const unsigned char *src_char;

	src_char = (const unsigned char *)src;
	dst_char = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	return dst;
}
