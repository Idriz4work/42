#include <stddef.h>    // For size_t
#include <stdlib.h>

void       *ft_memmove(void *dst, const void *src, size_t len)
{
	char *tmp;
	const char *ptrsrc;
	char *ptrdst;
	size_t i;
	size_t j;
	ptrsrc = src;
	ptrdst = dst;
	tmp = (char *)malloc(sizeof(char) * len);
	i = j = 0;
	while (j < len)
	{
		tmp[j] = ptrsrc[j];
		j++;
	}
	while (i < j)
	{
		ptrdst[i] = tmp[i];
		i++;
	}
	return ptrdst;
}

// #include <stdio.h>   // For printf
// #include <string.h>  // For comparison with the original memmove
// int main()
// {
//     char src[] = "Hello, World!";
//     char dst[50];
    
//     // Test ft_memmove with overlapping regions
//     printf("Original source: %s\n", src);
    
//     ft_memmove(dst, src, 3);  // Move 13 bytes from src to dst
//     printf("After ft_memmove: %s\n", dst);
    
//     // Compare with standard memmove for correctness
//     char src2[] = "Hello, World!";
//     char dst2[50];
    
//     memmove(dst2, src2, 3);  // Using standard memmove for comparison
//     printf("After standard memmove: %s\n", dst2);

//     return 0;
// }
