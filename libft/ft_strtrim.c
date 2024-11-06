
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: iatilla- <iatilla-@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/11/06 12:59:09 by iatilla-         #+#    #+#             */
/*   Updated: 2024/11/06 12:59:09 by iatilla-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}

int	check_letter(char c, char const *set, int indexes)
{
	static int begin_end;
	int i;

	i = 0;
	while (i < indexes)
	{
		if (c == ' ')
			begin_end = 1;
		if (c == set[i] && begin_end == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int i, j, total, indexes, condition;
	char *copy;

	indexes = ft_strlen(set);
	total = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * total + 1);
	if (!copy || total <= 0)
		return (NULL);
	i = j = condition = 0;
	while (s1[i] != '\0')
	{
		condition = check_letter(s1[i], set, indexes);
		if (condition == 1)
		{
			i++;
			continue ;
		}
		copy[j++] = s1[i++];
	}
	copy[i] = '\0';
	return (copy);
}

int	main(void)
{
	char s[] = "something is written here you can fork my repo and test it out :D";
	char set[] = "siwrte";
	printf("%s\n", ft_strtrim(s, set));
}
