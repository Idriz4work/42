#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
 const unsigned char *ptrsrc;
 unsigned char *ptrdst;
 size_t i;

 ptrsrc = (const unsigned char *)src;
 ptrdst = (unsigned char *)dst;
 if (ptrdst > ptrsrc && ptrdst < ptrsrc + len)
 {
  i = len;
  while (i > 0)
  {
   i--;
   ptrdst[i] = ptrsrc[i];
  }
 }
	i = 0;
	while (i < len)
	{
  ptrdst[i] = ptrsrc[i];
  i++;
	}
 return ptrdst;
}
// int main()
// {
//     char src[] = "Hello, World!";
//     char dst[50] = {0};   // Ensure the destination is initialized with null characters

//     // Test ft_memmove
//     printf("Original source: %s\n", src);

//     ft_memmove(dst, src, 3);  // Move 3 bytes from src to dst
//     dst[3] = '\0';  // Null-terminate the string to avoid garbage characters
//     printf("After ft_memmove: %s\n", dst);

//     // Compare with standard memmove
//     char src2[] = "Hello, World!";
//     char dst2[50] = {0};   // Ensure the destination is initialized with null characters

//     memmove(dst2, src2, 3);  // Using standard memmove for comparison
//     dst2[3] = '\0';  // Null-terminate for proper string display
//     printf("After standard memmove: %s\n", dst2);

//     return 0;
// }