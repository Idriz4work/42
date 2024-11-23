/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:15:08 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/21 17:42:24 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)s1)[i] != ((const unsigned char *)s2)[i])
			return (((const unsigned char *)s1)[i] - ((const unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
//   // Initialize destination and source arrays
//   char dst1[50] = {0};  // Enough space for the copied content
//   const char src[] = "yo my name is av";
//   const char src2[] = "yo my name is G"; 
//   int n = 20;

// 		int result_original = memcmp(src, src2, n);
//   int result_custom = ft_memcmp(src, src2, n);
//   // Print the results
//   printf("Original memccpy:\n");
//   printf("Result pointer: %d\n", result_original);
//   printf("\nCustom ft_memccpy:\n");
//   printf("Result pointer: %d\n", result_custom);
//   return (0);
// }