#include <stddef.h>    // For size_t

char *ft_strncat(char *s1,char *s2,size_t n)
{
	int i,j;
	i = j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && n > 0)
	{
		s1[i+j] = s2[j];
		j++;
		n--;
	}
	s1[i+j] = '\0';
	return s1;
}