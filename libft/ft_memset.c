// #include <stddef.h>    // For size_t

void       *ft_memset(void *s, int c, int len)
{
	int i;
	i = 0;
	char *ptrs;
	ptrs = s;
	while (i != len)
	{
		ptrs[i] = c;
		i++;
	}
	return ptrs;
}
// #include <stdio.h>   // For printf
// #include <string.h>  // For comparison with the original memmove
// int main()
// {
//     char src[] = "Hello, World!";
//     char dst[50];   
//     // Test ft_memmove with overlapping regions
//     printf("Original source: %s\n", src);
//     ft_memset(dst, 76,5);  // Move 13 bytes from src to dst
//     printf("After ft_memmove: %s\n", dst);
//     // Compare with standard memmove for correctness
//     char src2[] = "Hello, World!";
//     char dst2[50];
//     memset(dst2, 76,5);  // Using standard memmove for comparison
//     printf("After standard memmove: %s\n", dst2);
//     return 0;
// }
