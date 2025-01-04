/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:28:02 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/04 05:39:33 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(void)
{
	ft_printf("sa\n");
}

void	swap_b(void)
{
	ft_printf("sb\n");
}

void	sa_ab_same(void)
{
	ft_printf("ss\n");
}

void	push(int value, stack stak)
{
	stak.next = value;
	stak.next->next = NULL;
}

void	pop(stack stak)
{
	stak.anext = NULL;
}
