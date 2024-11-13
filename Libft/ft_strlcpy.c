/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:09:26 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/13 13:25:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;
				
	i = 0;
    if (size > 0)
    {
        while (src[i] != '\0' && i < size - 1)
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return ft_strlen(src);  
}

    // ft_memcpy(dst, src, src_len + 1);
        // ft_memcpy(dst, src, size - 1);

// int	main(void)
// {
// 	char	a[] = "hello it's donvieto";
// 	char	b[] = "\0";

// 	printf("ft: %zu\n", ft_strlcpy(a, b, 2));
// }
