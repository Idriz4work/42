/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:46:08 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/23 04:21:22 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	handle_edge(t_stk_top *stak, int list_size)
{
	if (list_size == 2 && (stak->a->contentt < stak->a->next->contentt)
		&& (stak->a->next->contentt > stak->a->next->next->contentt))
	{
		reversey_ra(stak);
		return ;
	}
	if (list_size == 1 && (stak->a->contentt > stak->a->next->contentt))
	{
		swap_a(stak);
		return ;
	}
	if (list_size == 2 && (stak->a->contentt > stak->a->next->contentt)
		&& (stak->a->next->contentt < stak->a->next->next->contentt))
	{
		push_b(stak->a->contentt, stak);
		push_b(stak->a->next->contentt, stak);
		pop_a(stak);
		swap_a(stak);
		return ;
	}
}

void	osman_sort_algorithm(t_stk_top *stak)
{
	int	value;

	value = ft_lstsize((t_list *)stak);
	if (value <= 2)
	{
		print_stack(stak, 'a');
		print_stack(stak, 'b');
		handle_edge(stak, value);
		print_stack(stak, 'a');
		print_stack(stak, 'b');
		return ;
	}
	while (stak->a != NULL)
	{
		value = stak->a->contentt;
		push_b(value, stak);
		pop_a(stak);
	}
	swap_a(stak);
	reversy_rb(stak);
	swap_b(stak);
	rotate_b(stak);
}
