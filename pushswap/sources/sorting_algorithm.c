/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:53:57 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/18 17:04:25 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// – For Divide
void	merge_sort(t_stk_top **stak, int left, int right)
{
	int		len;
	t_node	*stak_a;
	t_node	*current;

	stak_a = (*stak)->a;
	len = 0;
	current = stak_a;
	while (current)
	{
		len++;
		current = current->next;
	}
}
// – For Conquer and Combine
void	merge_sort_recursion(t_stk_top **stak, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		merge_sort_recursion(stak, left, mid);
		merge_sort_recursion(stak, mid + 1, right);
		merge_sort_array(stak, left, mid, right);
	}
}

void	merge_sort_array(t_stk_top **stak, int left, int mid, int right)
{
	int	left_len;
	int	right_len;
	int	tmp_left[left_len];
	int	tmp_right[right_len];

	left_len = mid - left + 1;
	right_len = right - mid;
}
