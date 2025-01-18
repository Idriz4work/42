/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:46 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/18 20:41:25 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_a(t_stk_top *staks)
{
	t_node	*first;
	t_node	*last;

	if (staks->a == NULL || staks->a->next == NULL)
		return ;
	first = staks->a;
	staks->a = first->next;
	last = staks->a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

void	rotate_b(t_stk_top *staks)
{
	t_node	*first;
	t_node	*last;

	if (staks->b == NULL || staks->b->next == NULL)
		return ;
	first = staks->b;
	staks->b = first->next;
	last = staks->b;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_printf("rb\n");
}

void	rotate_anb(t_stk_top *staks)
{
	rotate_a(staks);
	rotate_b(staks);
	ft_printf("rr\n");
}
void	reversey_ra(t_stk_top *staks)
{
	t_node	*slast;
	t_node	*last;

	if (staks->a == NULL || staks->a->next == NULL)
		return ;
	slast = staks->a;
	while (slast->next->next != NULL)
		slast = slast->next;
	last = slast->next;
	slast->next = NULL;
	last->next = staks->a;
	staks->a = last;
	ft_printf("rra\n");
}

void	reversy_rb(t_stk_top *staks)
{
	t_node	*slast;
	t_node	*last;

	if (staks->b == NULL || staks->b->next == NULL)
		return ;
	slast = staks->b;
	while (slast->next->next != NULL)
		slast = slast->next;
	last = slast->next;
	slast->next = NULL;
	last->next = staks->b;
	staks->b = last;
	ft_printf("rrb\n");
}
