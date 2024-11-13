/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:11:56 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/13 16:17:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	int	i;

	i = 0;
	if (s1 == NULL)
		return NULL;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return ((char *)&s1[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s1[i]);
	return (NULL);
}
// int	main(void)
// {
// 	char	s[] = "nuie\0dsf\n";
// 	char	c;

// 	c = '\n';
// 	printf("ft: %s\nnorm: %s\n", ft_strchr(NULL, c), strchr(NULL, c));
// }
