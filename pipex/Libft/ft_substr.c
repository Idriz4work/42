/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:06:08 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/16 15:27:24 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	slen;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	slen = ft_strlen(s);
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// int main()
// {
// 	int i = 39;
// 	int len = 40;
// 	const char s[] = "my name is atikopati how are you doing ?";
// 	printf("my: %s\n",ft_substr(s,i,len));
// }
