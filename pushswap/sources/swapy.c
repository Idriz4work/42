/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:28:02 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/24 07:51:34 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_stack_top **stak)
{
	t_list	*first;
	t_list	*second;

	if ((*stak)->a == NULL || (*stak)->a->next == NULL)
		return ;
	first = (*stak)->a;
	second = (*stak)->a->next;
	first->next = second->next;
	second->next = first;
	(*stak)->a = second;
	ft_printf("sa\n");
}

void	swap_b(t_stack_top **stak)
{
	t_list	*first;
	t_list	*second;

	if ((*stak)->b == NULL || (*stak)->b->next == NULL)
		return ;
	first = (*stak)->b;
	second = (*stak)->b->next;
	first->next = second->next;
	second->next = first;
	(*stak)->b = second;
	ft_printf("sb\n");
}

void	sa_ab_same(t_stack_top **stak)
{
	swap_a(stak);
	swap_b(stak);
	ft_printf("ss\n");
}

void	reversey_rev_rrr(t_stack_top **stak)
{
	reversey_ra(*stak);
	reversy_rb(*stak);
	ft_printf("rrr\n");
}
