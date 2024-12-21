/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:14:58 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/16 22:28:38 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_char;
	const unsigned char	*src_char;

	i = 0;
	dst_char = (unsigned char *)dst;
	src_char = (const unsigned char *)src;
	if (n == 0)
		return (dst);
	if (dst == NULL && src == NULL)
		return (dst);
	if (dst == NULL || src == NULL)
	{
		dst_char[i] = src_char[i];
		return (dst_char);
	}
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	return ((void *)dst_char);
}

// int	main(void)
// {
// 	// Test 1: Basic usage with partial copy
// 	int i = 0;
// 	char s[] = "hello bob was here";
// 	char s2[] = "hello ati was here";
// 	ft_memcpy(s, s2, i);
// 	printf("FT Partial Copy: %s\n", s);

// 	char s1[] = "hello bob was here";
// 	char s21[] = "hello ati was here";
// 	memcpy(s1, s21, i);
// 	printf("ORI Partial Copy: %s\n", s1);

// 	// Test 2: Full copy
// 	char full_src[] = "A complete sentence";
// 	char full_dst[20];
// 	ft_memcpy(((void*)0), ((void*)0), 3);

// 	char full_src1[] = "A complete sentence";
// 	char full_dst1[20];
// 	memcpy(((void*)0), ((void*)0), 3);
// 	printf("ORI Full Copy: %s\n", full_dst1);

// // 	// Test 3: n = 0, should not copy anything
// // 	char zero_src[] = "unchanged";
// // 	char zero_dst[] = "destination";
// // 	ft_memcpy(zero_dst, zero_src, 0);
// // 	printf("FT No Copy (n=0): %s\n", zero_dst);

// // 	memcpy(zero_dst, zero_src, 0);
// // 	printf("ORI No Copy (n=0): %s\n", zero_dst);

// // 	// Test 4: NULL source or destination
// // 	char *null_dst = NULL;
// // 	char null_src[] = "source";
// // 	printf("FT NULL Source: %s\n", ft_memcpy(null_dst, null_src, 4));

// // 	char *null_src_ptr = NULL;
// // 	char null_dst_arr[] = "destination";
// // 	printf("FT NULL Dest: %p\n", ft_memcpy(null_dst_arr, null_src_ptr, 4));
// }