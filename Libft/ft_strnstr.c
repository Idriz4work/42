/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:07:50 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/13 13:36:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (little[0] == '\0' || big == little)
		return ((char *)big);
	while (big[j] != '\0' && j < len)
	{
		i = 0;
		while (big[j+i] != '\0' && big[j + i] == little[i] && j + i < len)
		{
			if (little[i + 1] == '\0')
				return ((char *)&big[j]);
			i++;
		}
		j++;
	}
	return (NULL);
}
// #include <string.h>

// int	main(void)
// {
// 	char	s[] = "abcdefgh";
// 	char	big[] = "def";
// 	printf("ft: %s\n", ft_strnstr(s, big, 31));
// }
