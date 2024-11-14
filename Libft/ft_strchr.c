/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:11:56 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/14 16:34:16 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return ((char *)&s1[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s1[i]);
	return ((char *)&s1[i]);
}
// int	main(void)
// {
// 	char	*s = NULL;
// 	char	c;

// 	c = 's';
// 	printf("ft: %s\n", ft_strchr(((void*)0), '\0'));
// }