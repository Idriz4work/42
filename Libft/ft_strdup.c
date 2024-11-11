/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:10:42 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:10:46 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	copy = (char *)malloc(j) + 1;
	if (copy == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
//  char src[] = "y what uppp";
//  // Call your custom strdup and standard library strdup
//  char *my_copy = ft_strdup(src);
//  char *std_copy = strdup(src);
//  // Print both results to compare
//  printf("MY: %s\n", my_copy);
//  printf("OR: %s\n", std_copy);
// }