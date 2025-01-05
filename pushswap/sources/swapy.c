/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:28:02 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/05 16:08:38 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stk_top	*swap_a(t_stk_top *stak)
{
	t_node *second;
	t_node *first;

	first = stak->a;
	second = stak->a->next;
	if (stak->a == NULL)
		return stak;
	stak->a = first;
	stak->a->next = second;
	stak->a->next->next = NULL;
	ft_printf("sa\n");
	return (stak);
}

t_stk_top	*swap_b(t_stk_top *stak)
{
	t_node *second;
	t_node *first;

	first = stak->b;
	second = stak->b->next;
	if (stak->b == NULL)
		return stak;
	stak->b = first;
	stak->b->next = second;
	stak->b->next->next = NULL;
	ft_printf("sb\n");
	return (stak);
}

t_stk_top	*sa_ab_same(t_stk_top *stak)
{
	swap_a(stak);
	swap_b(stak);
	ft_printf("ss\n");
	return (stak);
}

t_stk_top*	reversey_rev_ranrb(t_stk_top* stak)
{
	ft_printf("rrr\n");
	return (stak);
}
