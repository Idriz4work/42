#include "libft.h" For size_t

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && n > 0)
	{
		if (!(s1[i] == s2[i]))
			return (1);
		i++;
	}
	return (0);
}
