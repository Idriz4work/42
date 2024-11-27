/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:09:36 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 18:02:54 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*copy(char *s1, const char *s2, size_t n, size_t s1_len)
{
	size_t	j;
	size_t	i;

	i = s1_len;
	j = 0;
	while (s2[j] != '\0' && i < n - 1)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[s2_len] != '\0')
		s2_len++;
	if (n <= s1_len)
		return (n + s2_len);
	s1 = copy(s1, s2, n, s1_len);
	return (s1_len + s2_len);
}
