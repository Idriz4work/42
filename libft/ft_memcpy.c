#include <stddef.h>    // For size_t

void       *ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;
	i = 0;
 unsigned char *dst_char;
 const unsigned char *src_char;

	src_char = (const unsigned char *)src;
	dst_char = (unsigned char *)dst;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	return dst;
}
