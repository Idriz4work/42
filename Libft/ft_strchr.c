/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:11:56 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/12 19:07:07 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	int	i;

	i = 0;
	if (!s1 || s1 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return ((char *)&s1[i]);
		i++;
	}
	if (s1[i] == '\0' && c == '\0')
		return ((char *)&s1[i]);
	i++;
	return (NULL);
}
// int	main(void)
// {
// 	char	s[] = "sdggs\r\t\r\t\0";
// 	char	c;

// 	c = 's';
// 	printf("ft: %s\nnorm: %s\n", ft_strchr(s, c), strchr(s, c));
// }