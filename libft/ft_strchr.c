#include <stdio.h>
#include <string.h>

// Function to find the first occurrence of character `c` in the string `s`
char *ft_strchr(char *s1, char c)
{
 int i = 0;
 while (s1[i] != '\0')
 {
  if (s1[i] == c)
   return &s1[i];
  i++;
 }
 return NULL;
}
// int main()
// {
//     char s[] = "Dollar dollar dollat is what I need yea yea";
//     char c = 'd'; // Search for the first occurrence of 'd'
   
//     printf("ft: %s\nnorm: %s\n", ft_strchr(s, c), strchr(s,c));
// }
