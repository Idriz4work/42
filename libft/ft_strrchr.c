#include <stdio.h>
#include <stdio.h>
#include <string.h>

int ft_strlen(char *s)
{
 int i = 0;
 while (s[i] != '\0')
	 i++;
 return i;
}

char *ft_strrchr(char *s1, char c)
{
  int n;
		n = ft_strlen(s1);
  
  while (n >= 0)
  {
      if (s1[n] == c)
          return &s1[n];
      n--;
  }
  return NULL;
}

int main()
{
    char s[] = "Dollar dollar dollat is what I need yea yea";
    char c = 'd'; // Search for the first occurrence of 'd'
   
    printf("ft: %s\nnorm: %s\n", ft_strrchr(s, c), strrchr(s,c));
}

