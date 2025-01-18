/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:28:02 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/18 20:23:11 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_stk_top *stak)
{
	t_node	*first;
	t_node	*second;
	t_node	*remainder;

	if (stak->a == NULL || stak->a->next == NULL)
		return ;
	first = stak->a;
	second = first->next;
	remainder = second->next;

	stak->a = first;
	first->next = second;
	second->next = remainder;
	ft_printf("sa\n");
}

void	swap_b(t_stk_top *stak)
{
	t_node	*first;
	t_node	*second;
	t_node	*remainder;

	if (stak->b == NULL || stak->b->next == NULL)
		return ;
	first = stak->b;
	second = first->next;
	remainder = second->next;

	stak->b = first;
	first->next = second;
	second->next = remainder;
	ft_printf("sb\n");
}

void	sa_ab_same(t_stk_top *stak)
{
	swap_a(stak);
	swap_b(stak);
	ft_printf("ss\n");
}

void	reversey_rev_rrr(t_stk_top *stak)
{
	reversey_ra(stak);
	reversy_rb(stak);
	ft_printf("rrr\n");
}
