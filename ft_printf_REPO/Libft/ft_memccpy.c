/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:15:39 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:29:08 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, size_t c, size_t n)
{
	size_t				i;
	unsigned char		*dst_char;
	const unsigned char	*src_char;

	dst_char = (unsigned char *)dst;
	src_char = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		if (src_char[i] == (unsigned char)c)
			return ((void *)(dst_char + i + 1));
		i++;
	}
	return (NULL);
}

// int main()
// {
//   // Initialize destination and source arrays
//   char dst1[50] = {0};  // Enough space for the copied content
//   char dst2[50] = {0};  // Another destination array for comparison
//   char src[] = "zo my name is";
//   int c = 'a';
//   int n = 8;
//   // Test the original memccpy function
//   void *result_original = memccpy(dst1, src, c, n);
//   // Test your custom ft_memccpy function
//   void *result_custom = ft_memccpy(dst2, src, c, n);
//   // Print the results
//   printf("Original memccpy:\n");
//   printf("Result pointer: %p\n", result_original);
//   printf("Destination string: %s\n", dst1);
//   printf("\nCustom ft_memccpy:\n");
//   printf("Result pointer: %p\n", result_custom);
//   printf("Destination string: %s\n", dst2);
//   return (0);
// }