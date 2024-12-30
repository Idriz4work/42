/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:09:26 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/14 11:14:18 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	if (i < size)
	{
		while (s2[i] != '\0' && i < size - 1)
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
	}
	return (ft_strlen(s2));
}

// int	main(void)
// {
// 	char	a[] = "hello it's donvieto";
// 	char	b[] = "\0";

// 	printf("ft: %zu\n", ft_strlcpy(a, b, 2));
// }
