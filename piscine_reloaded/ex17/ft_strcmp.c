/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:21:57 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/07 15:08:13 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (!(s1[i] == s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>
// int main()
// {
//     char s[] = "21helloO";
//     char s2[] = "Hello";
//     printf("ft: %i\n%i\n",ft_strcmp(s,s2),strcmp(s,s2));
// }
