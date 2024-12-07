/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:00:14 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/07 22:10:26 by iatilla-         ###   ########.fr       */
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
	size_t	i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!copy || !src)
		return (NULL);
	while (i < ft_strlen(src))
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	str = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
