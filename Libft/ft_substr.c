/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:06:08 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/12 10:31:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	sub = (char *)malloc(sizeof(char) * len);
	if (!sub || !s)
		return (NULL);
	if (start >= len)
		return (NULL);
	while (len-- > 0)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i + 1] = '\0';
	return (sub);
}

// int main()
// {
// 	int i = 0;
// 	int len = 1;
// 	const char s[] = "my name is atikopati how are you doing ?";
// 	printf("my: %s\n",ft_substr(s,i,len));
// }