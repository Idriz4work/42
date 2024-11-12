/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:14:40 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/12 11:14:54 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptrs;

	i = 0;
	ptrs = s;
	while (i < len)
	{
		ptrs[i] = c;
		i++;
	}
	s = ptrs;
	return (s);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
//  char src[] = "Hello, World!";
//  char dst[50];
//  // Test ft_memmove with overlapping regions
//  printf("Original source: %s\n", src);
//  ft_memset(dst, 'y',20);  // Move 13 bytes from src to dst
//  printf("After ft_memmove: %s\n", dst);
//  // Compare with standard memmove for correctness
//  char src2[] = "Hello, World!";
//  char dst2[50];
//  memset(dst2, 'y',20);  // Using standard memmove for comparison
//  printf("After standard memmove: %s\n", dst2);
//  return (0);
// }
