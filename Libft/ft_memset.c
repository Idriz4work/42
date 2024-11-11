/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:14:40 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:43:18 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, size_t c, size_t len)
{
	size_t			i;
	unsigned char	*ptrs;

	i = 0;
	ptrs = s;
	while (i != len)
	{
		ptrs[i] = c;
		i++;
	}
	return (NULL);
}
// #include <stdio.h>   // For printf
// #include <string.h>  // For comparison with the original memmove
// int main()
// {
//     char src[] = "Hello, World!";
//     char dst[50];
//     // Test ft_memmove with overlapping regions
//     printf("Original source: %s\n", src);
//     ft_memset(dst, 76,5);  // Move 13 bytes from src to dst
//     printf("After ft_memmove: %s\n", dst);
//     // Compare with standard memmove for correctness
//     char src2[] = "Hello, World!";
//     char dst2[50];
//     memset(dst2, 76,5);  // Using standard memmove for comparison
//     printf("After standard memmove: %s\n", dst2);
//     return (0);
// }