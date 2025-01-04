/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:10:42 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/12 18:05:32 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!copy || !src)
		return (NULL);
	while (i < ft_strlen(src))
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
//  char src[] = "y what uppp\n";
//  // Call your custom strdup and standard library strdup
//  char *my_copy = ft_strdup(src);
//  char *std_copy = strdup(src);
//  // Print both results to compare
//  int fd = open("test.txt",O_RDWR);
//  ft_putstr_fd(my_copy,fd);
//  ft_putstr_fd(std_copy,fd);
// }