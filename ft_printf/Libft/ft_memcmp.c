/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:15:08 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:42:55 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptrs1;
	const unsigned char	*ptrs2;

	ptrs1 = (const unsigned char *)s1;
	ptrs2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptrs1[i] != ptrs2[i])
			return (ptrs1[i] - ptrs2[i]);
		i++;
	}
	return (0);
}
// #include <stdio.h>
// int main()
// {
//   // Initialize destination and source arrays
//   char dst1[50] = {0};  // Enough space for the copied content
//   char src[] = "yo my name is av";
//   char src2[] = "yo my name is G"; 
	// Another destination array for comparison
//   int n = 20;

// 		void *result_original = memcmp(src, src2, n);
//   void *result_custom = ft_memcmp(src, src2, n);
//   // Print the results
//   printf("Original memccpy:\n");
//   printf("Result pointer: %p\n", result_original);
//   printf("\nCustom ft_memccpy:\n");
//   printf("Result pointer: %p\n", result_custom);
//   return (0);
// }