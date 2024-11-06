#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memoryplace;
	size_t	i;
	size_t	total;

	i = 0;
	total = size * count;
	memoryplace = (char *)malloc(total);
	if (memoryplace == 0)
		return (NULL);
	while (i < total)
	{
		memoryplace[i] = 0;
		i++;
	}
	return (memoryplace);
}

// Custom strlen function
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}

char	*allocatespace(char **str, int len1, int len2)
{
	*str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (*str == NULL)
		return (NULL);
	return (*str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = allocatespace(&str, len1, len2);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}
