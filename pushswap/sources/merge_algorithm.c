/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:48:04 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/24 03:28:17 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// – For Conquer and Combine
// void	merge(t_stk_top *stak, int left_array[], int right_array[])
// {
	// int	left_size;
	// int	right_size;
	// int	right;
	// int	left;

	// left_size = ft_lstsize(left_array) / 2;
	// right_size = ft_lstsize(right_array) - left_size;
	// right = 0;
	// left = 0;
	// while (left < left_size && right < right_size)
	// {
	// 	if (left_array[left] < right_array[right])
	// 	{
	// 		push_a(left_array[left], stak);
	// 		left++;
	// 	}
	// 	else
	// 	{
	// 		push_a(right_array[right], stak);
	// 		right++;
	// 	}
	// }
	// while (left < left_size)
	// {
	// 	push_a(left_array[left], stak);
	// 	left++;
	// }
	// while (right < right_size)
	// {
	// 	push_a(right_array[right], stak);
	// 	right++;
	// }
// }

// – For Divide
// void	merge_sort(t_stk_top *stak)
// {
	// int	len;
	// int	mid;
	// int	left_array[mid];
	// int	right_array[len - mid];
	// int	i;
	// int	j;

	// len = ft_lstsize(stak->a);
	// mid = len / 2;
	// while (i < len)
	// {
	// 	if (i < mid)
	// 		left_array[i] = stak->a;
	// 	else
	// 		right_array[j++] = stak->a;
	// 	i++;
	// }
	// merge_sort(left_array);
	// merge_sort(right_array);
	// merge(left_array, right_array, stak);
// }
