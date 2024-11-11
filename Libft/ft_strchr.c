/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:11:56 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:58:09 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s1, int c)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
// int main()
// {
//     char s[] = "Dollar dollar dollat is what I need yea yea";
//     char c = 'd'; // Search for the first occurrence of 'd'

//     printf("ft: %s\nnorm: %s\n", ft_strchr(s, c), strchr(s,c));
// }