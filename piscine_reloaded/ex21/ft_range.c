/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:35:37 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/06 10:46:55 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// #include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;
	int	j;
	int	difference;

	difference = max - min;
	array = malloc(sizeof(int) * difference + 1);
	if (!array || min >= max)
		return (NULL);
	i = 0;
	j = 0;
	while (i <= difference)
	{
		array[j] = i;
		printf("%i", array[i]);
		i++;
		j++;
	}
	array[i] = '\0';
	return (array);
}

// int main()
// {
//     int i;

//     i = 0;
//     int *result = ft_range(1,20);
//     while (result[i] != '\0')
//     {
//         printf("%i",result[i]);
//         i++;
//     }
// }
