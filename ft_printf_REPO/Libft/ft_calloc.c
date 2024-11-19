/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:19:14 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:34:03 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memoryplace;
	size_t	i;
	size_t	total;

	i = 0;
	total = size * count;
	memoryplace = (char *)malloc(total);
	if (memoryplace == 0)
		return (NULL);
	while (i < total)
	{
		memoryplace[i] = 0;
		i++;
	}
	return (memoryplace);
}
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     // Test 1: Allocate an array of 5 integers
//     size_t count = 5;
//     size_t size = sizeof(int);
//     int *arr = (int *)ft_calloc(count, size);

//     // Check if memory was allocated
//     if (arr == NULL)
//     {
//         printf("Memory allocation failed\n");
//         return (1);
//     }

//     // Check if the memory is zero-initialized
//     printf("Test 1: Allocating memory for 5 integers.\n");
//     for (size_t i = 0; i < count; i++)
//     {
//         printf("arr[%zu] = %d\n", i, arr[i]);
//         if (arr[i] != 0)
//         {
//             printf("Error: Memory not initialized to zero.\n");
//             free(arr); // Always free the allocated memory
//             return (1);
//         }
//     }

//     free(arr); // Free the allocated memory after test

//     // Test 2: Allocate zero size, should return NULL or valid pointer
//     int *zero_arr = (int *)ft_calloc(0, sizeof(int));
//     printf("\nTest 2: Allocating zero size.\n");
//     if (zero_arr == NULL)
//     {
//         printf("Correct: Returned NULL for zero size.\n");
//     }
//     else
//     {
//         printf("Returned a valid pointer for zero size.\n");
//         free(zero_arr);
//     }

//     // Test 3: Large allocation (check failure)
//     size_t large_count = SIZE_MAX;
//     int *large_arr = (int *)ft_calloc(large_count, size);
//     printf("\nTest 3: Attempting large allocation.\n");
//     if (large_arr == NULL)
//     {
//      printf("Correct: Large allocation failed, returned NULL.\n");
//     }
//     else
//     {
//         printf("Error: Large allocation did not fail as expected.\n");
//         free(large_arr);
//     }

//     return (0);
// }