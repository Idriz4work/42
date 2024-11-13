/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:07:25 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/13 09:30:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	int	n;

	n = ft_strlen(s1);
	while (n >= 0)
	{
		if (s1[n] == c)
			return ((char *)&s1[n]);
		n--;
	}
	return (NULL);
}
// int	main(void)
// {
// 	char s[] = "Dollar dollar dollat is what I need yea yea";
// 	char c = 'd'; // Search for the first occurrence of 'd'
// 	printf("ft: %s\nnorm: %s\n", ft_strrchr(s, c), strrchr(s, c));
// }