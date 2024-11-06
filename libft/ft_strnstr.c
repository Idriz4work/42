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

#include <stddef.h>
#include <stdio.h>
#include <string.h>


int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(char *s1, char *s2, size_t n)
{
	size_t i;
	size_t len;
	char c;

	c = *s2;
	if (c == '\0')
		return (0);
	len = ft_strlen(s2);
	while (len <= n)
	{
		if (*s1 == c)
		{
			while (i == 1)
			{
				if (i == len)
					return ((char *)s1);
				if (s1[i] != s2[i])
					break ;
				i++;
			}
		}
		n--;
		s1++;
	}
	return (0);
}

int	main(void)
{
	char s[] = "hello I'm back";
	char s1[] = "hello I'm gone";
	printf("ft: %s\n%s\n", ft_strnstr(s, s1, 8), strnstr(s, s1, 8));
}
