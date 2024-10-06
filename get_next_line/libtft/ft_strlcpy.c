#include <stddef.h>    // For size_t

int ft_strlcpy(char *s1,char *s2, size_t size)
{
	int i;
	i = 0;
	int retsize;
	retsize = 0;
	while (s2[retsize] != '\0')
		retsize++;
	while (s2[i] != '\0' && size > 1)
	{
		s1[i] = s2[i];
		i++;
		size--;
	}
	s1[i] = '\0';
	return retsize;
}
