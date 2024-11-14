/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:14:50 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/14 11:04:25 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*ptrsrc;
	char		*ptrdst;
	size_t		i;

	i = 0;
	ptrsrc = (const char *)src;
	ptrdst = (char *)dst;
	if (!dst && !src)
		return (NULL);
	if (ptrdst > ptrsrc && ptrdst < len + ptrsrc)
	{
		while (len-- > 0)
			ptrdst[len] = ptrsrc[len];
		return (ptrdst);
	}
	while (i < len)
	{
		ptrdst[i] = ptrsrc[i];
		i++;
	}
	return (ptrdst);
}
// int main()
// {
//     char src[] = "_bnds_";
//     char dst[50] = {0};

//     // Test ft_memmove
//     printf("Original source: %s\n", src);

//     ft_memmove(dst, src, 3);  // Move 3 bytes from src to dst
//     dst[3] = '\0';  // Null-terminate the string to avoid garbage characters
//     printf("After ft_memmove: %s\n", dst);

//     // Compare with standard memmove
//     char src2[] = "_bnds_";
//     char dst2[50] = {0};

//     memmove(dst2, src2, 3);  // Using standard memmove for comparison
//     dst2[3] = '\0';  // Null-terminate for proper string display
//     printf("After standard memmove: %s\n", dst2);
//     return (0);
// }