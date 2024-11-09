
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: iatilla- <iatilla-@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/11/06 12:59:09 by iatilla-         #+#    #+#             */
/*   Updated: 2024/11/06 12:59:09 by iatilla-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strrchr(char *s1, char c)
{
	int n;

	n = ft_strlen(s1);
	while (n >= 0)
	{
		if (s1[n] == c)
			return (&s1[n]);
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
