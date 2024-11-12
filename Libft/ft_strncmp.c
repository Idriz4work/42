/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:08:20 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/12 19:07:37 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (1);
	while (((*s1) || (*s2)) && (n > i))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
// #include <string.h>
// int	main(void)
// {
// 	char s[] = "sdgjkahgnbg\r\t\r\thmgpdjgoehsdb\0";
// 	char s1[] = "sdgjkahgnbg\r\t\r\thmgpdjgoehsdb\0";
// 	printf("ft: %d\n%d\n", ft_strncmp(s, s1, -1),strncmp(s, s1, -1));
// }
