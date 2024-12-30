/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:08:47 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:08:52 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s || !copy)
		return (NULL);
	while (s[i] != '\0')
	{
		copy[i] = (*f)(i, s[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// char to_upper_if_space(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 		return (c -= 32); // Convert to uppercase if index is even
// 	else
// 		return (c);          // Otherwise, leave as-is
// }
// int main()
// {
// 	char s[] = "Hello World!";

// 	// Call ft_strmapi with the string and transformation function
// 	char *result = ft_strmapi(s, to_upper_if_space);

// 	if (result) {
// 		printf("Original string: %s\n", s);
// 		printf("Transformed string: %s\n", result);
// 		free(result); // Free the allocated memory
// 	} else {
// 		printf("Memory allocation failed.\n");
// 	}

// 	return (0);
// }