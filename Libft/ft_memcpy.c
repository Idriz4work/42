/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:14:58 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:27:03 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_char;
	const unsigned char	*src_char;

	src_char = (const unsigned char *)src;
	dst_char = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	return (dst);
}
