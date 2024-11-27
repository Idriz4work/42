/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:15:19 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:41:52 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*pointer;

	i = 0;
	pointer = (const char *)s;
	while (i < n)
	{
		if (pointer[i] == (char)c)
			return ((void *)pointer + i);
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     const char *s1 = "hello";
//     const char *s2 = "herro";
//     int c = 'r';
//     int n = 4;
//     // Test the original memchr function
//     void *result1 = memchr(s2, c, n);
//     // Test your custom ft_memchr function
//     void *result2 = ft_memchr(s2, c, n);
//     // Print results for both functions
//     printf("Original memchr:\nPointer: %p\nString: %s\n\n", result1, s2);
//     printf("Custom ft_memchr:\nPointer: %p\nString: %s\n\n", result2, s2);
//     return (0);
// }