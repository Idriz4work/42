#include <stddef.h>    // For size_t

void       *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	const char *pointer;

	i = 0;
	pointer = (const unsigned char *)s;
	while (i < n)
	{
		if (pointer[i] == (unsigned char)c)
			return (void *)pointer + i;
		i++;
	}
	return NULL;
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     const char *s1 = "hello";
//     const char *s2 = "herro";
//     int c = 'r';
//     int n = 4;
//     // Test the original memchr function
//     void *result1 = memchr(s2, c, n);
//     // Test your custom ft_memchr function
//     void *result2 = ft_memchr(s2, c, n);
//     // Print results for both functions
//     printf("Original memchr:\nPointer: %p\nString: %s\n\n", result1, s2);
//     printf("Custom ft_memchr:\nPointer: %p\nString: %s\n\n", result2, s2);
//     return 0;
// }
