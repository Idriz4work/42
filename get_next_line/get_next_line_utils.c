/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:00:14 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/08 20:02:04 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	readfile_helper(int bytes, char **temp)
{
	if (bytes > 0)
		return (2);
	if (bytes == 0)
	{
		free(*temp);
		return (0);
	}
	else
	{
		free(*temp);
		return (-1);
	}
}

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		i;
	int		len;

	len = 0;
	while (src[len] != '\0')
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy || !src)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*memoryplace;
	size_t	total;
	size_t	i;

	total = size * count;
	memoryplace = (char *)malloc(total);
	if (memoryplace == 0)
		return (NULL);
	i = 0;
	while (i < total)
	{
		memoryplace[i] = 0;
		i++;
	}
	return (memoryplace);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = malloc(i + j + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
