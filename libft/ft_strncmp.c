#include "libft.h" 

int	ft_strncmp(const char *s1,const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && n > i)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
// #include <string.h>
// int	main(void)
// {
// 	char s[] = "hellKo I'm back";
// 	char s1[] = "helKlo I'm gone";
// 	printf("ft: %d\n%d\n", ft_strncmp(s, s1, 12),strncmp(s, s1, 12));
// }
