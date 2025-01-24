/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:46:08 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/24 03:36:49 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	osman_sort_algorithm(t_stack_top *stak)
{
	int	value;
	int	starting_point;

	value = 0;
	starting_point = check_sorted(stak);
	while (stak->a != NULL)
	{
		value = stak->a->content;
		push_b(value, stak);
		pop_a(stak);
	}
}
