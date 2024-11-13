/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:14:58 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/13 15:51:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (dst_char);
}

// int main()
// {
//     // Test 1: Basic usage with partial copy
//     int i = 0;
//     char s[] = "hello bob was here";
//     char s2[] = "hello ati was here";
//     ft_memcpy(s, s2, i);
//     printf("FT Partial Copy: %s\n", s);

//     char s1[] = "hello bob was here";
//     char s21[] = "hello ati was here";
//     memcpy(s1, s21, i);
//     printf("ORI Partial Copy: %s\n", s1);

//     // Test 2: Full copy
//     char full_src[] = "A complete sentence";
//     char full_dst[20];
//     ft_memcpy(full_dst, full_src, strlen(full_src) + 1);  // Copy entire string including null terminator
//     printf("FT Full Copy: %s\n", full_dst);

//     char full_src1[] = "A complete sentence";
//     char full_dst1[20];
//     memcpy(full_dst1, full_src1, strlen(full_src1) + 1);
//     printf("ORI Full Copy: %s\n", full_dst1);

//     // Test 3: n = 0, should not copy anything
//     char zero_src[] = "unchanged";
//     char zero_dst[] = "destination";
//     ft_memcpy(zero_dst, zero_src, 0);
//     printf("FT No Copy (n=0): %s\n", zero_dst);

//     memcpy(zero_dst, zero_src, 0);
//     printf("ORI No Copy (n=0): %s\n", zero_dst);

//     // Test 4: NULL source or destination
//     char *null_dst = NULL;
//     char null_src[] = "source";
//     printf("FT NULL Source: %p\n", ft_memcpy(null_dst, null_src, 4));

//     char *null_src_ptr = NULL;
//     char null_dst_arr[] = "destination";
//     printf("FT NULL Dest: %p\n", ft_memcpy(null_dst_arr, null_src_ptr, 4));

// 				// Test 4: NULL source or destination ORGINAL
//     // char *null_dst1 = NULL;
//     // char null_src1[] = "source";
//     // printf("ORI NULL Source: %p\n", memcpy(null_dst1, null_src1, 4));

//     // char *null_src_ptr1 = NULL;
//     // char null_dst_arr1[] = "destination";
//     // printf("ORI NULL Dest: %p\n", memcpy(null_dst_arr1, null_src_ptr1, 4));

//     // Test 5: Overlapping memory (not recommended, but for testing purposes)
//     char overlap_src[] = "overlap test";
//     printf("FT Overlap Test Before: %s\n", overlap_src);
//     ft_memcpy(overlap_src + 5, overlap_src, 7);  // overlapping copy
//     printf("FT Overlap Test After: %s\n", overlap_src);

//     char overlap_src1[] = "overlap test";
//     printf("ORI Overlap Test Before: %s\n", overlap_src1);
//     memcpy(overlap_src1 + 5, overlap_src1, 7);  // overlapping copy
//     printf("ORI Overlap Test After: %s\n", overlap_src1);

//     return 0;
// }
