/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:19:26 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/26 15:09:48 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*pointer;

	i = 0;
	pointer = s;
	while (i < n)
	{
		pointer[i] = 0;
		i++;
	}
}

// #include <stdio.h>
// #include <strings.h>
// int main()
// {
//  // Declare s as a char array (or any data type like unsigned char)
//  char s[10000] = "Hello, world!";
//  // Print the initial value of the array
//  printf("Before bzero:\n");
//  printf("MY: %s\n", s);
//  // Call your function to zero out the first 3 bytes
//  ft_bzero(s, 3);
//  // Call the standard bzero function to compare results
//  bzero(s, 3);
//  // Print after bzero and ft_bzero to see the results
//  printf("After ft_bzero (MY): %s\n", s);
//
//  printf("After bzero (ORI): %s\n", s);
//  return (0);
// }