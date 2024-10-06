#include <stdlib.h>

char *ft_strdup(char *src)
{
	int i,j;
	i = j = 0;
	while (src[j] != '\0')
		j++;
	char *copy;
	copy = (char *)malloc(j) + 1;
	if (copy == NULL) // Check if malloc failed
  return NULL;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return copy;
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
//  char src[] = "y what uppp";
//  // Call your custom strdup and standard library strdup
//  char *my_copy = ft_strdup(src);
//  char *std_copy = strdup(src); 
//  // Print both results to compare
//  printf("MY: %s\n", my_copy);
//  printf("OR: %s\n", std_copy);   
// }
