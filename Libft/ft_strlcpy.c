/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:09:26 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/12 18:08:29 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	src_size;

	src_size = 0;
	if (size == 0)
        return src_size;
	i = ft_strlen(s2);
	if (i == 0)
		return i;
	i = 0;
	while (s2[src_size] != '\0')
		src_size++;
	while (s2[i] != '\0' && i < size - 1)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (src_size);
}

// int	main(void)
// {
// 	char	a[] = "hello it's donvieto";
// 	char	b[] = "\0";

// 	printf("ft: %zu\n", ft_strlcpy(a, b, 2));
// }
