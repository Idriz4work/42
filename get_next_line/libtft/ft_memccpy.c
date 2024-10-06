#include <stddef.h>    // For size_t

void       *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;
 unsigned char *dst_char = (unsigned char *)dst;   // Cast to unsigned char*
 const unsigned char *src_char = (const unsigned char *)src;  // Cast to const unsigned char*
	while (i < n)
	{
		if (src_char[i] == (unsigned char)c)
			return dst_char + i + 1;
		dst_char[i] = src_char[i];
		i++;
	}
	// if c is not found
	return NULL;
}
