/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:07:50 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/12 18:15:04 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < len)
	{
		i = 0;
		while (big[j + i] == little[i] && j + i < len)
		{
			if (little[i + 1] == '\0')
				return ((char *)big);
			i++;
		}
		j++;
	}
	return (NULL);
}
// #include <string.h>

// int	main(void)
// {
// 	char	s[] = "hello I'm back";
// 	char	big[] = "hel";

// 	printf("ft: %s\n", ft_strnstr(s, big, 3));
// }