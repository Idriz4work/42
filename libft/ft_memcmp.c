#include <stddef.h>    // For size_t

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
 size_t i = 0;
 const unsigned char *ptrs1;
 const unsigned char *ptrs2;

	ptrs1 = (const unsigned char *)s1;
	ptrs2 = (const unsigned char *)s2;
 while (i < n)
 {
  if (ptrs1[i] != ptrs2[i])
   return (ptrs1[i] - ptrs2[i]);
  i++;
 }
 return NULL;
}
// #include <stdio.h>
// int main()
// {
//   // Initialize destination and source arrays
//   char dst1[50] = {0};  // Enough space for the copied content
//   char src[] = "yo my name is av";
//   char src2[] = "yo my name is G";  // Another destination array for comparison
//   int n = 20;
  
// 		void *result_original = memcmp(src, src2, n);
//   void *result_custom = ft_memcmp(src, src2, n);
//   // Print the results
//   printf("Original memccpy:\n");
//   printf("Result pointer: %p\n", result_original);
//   printf("\nCustom ft_memccpy:\n");
//   printf("Result pointer: %p\n", result_custom);
//   return 0;
// }