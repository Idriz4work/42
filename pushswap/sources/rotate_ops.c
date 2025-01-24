/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:46 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/24 07:52:26 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


void rotate_a(t_stack_top **staks)
{
    t_list *first;
    t_list *last;

    if ((*staks)->a == NULL || (*staks)->a->next == NULL)
        return ;
    first = (*staks)->a;
    (*staks)->a = first->next;
    last = (*staks)->a;
    while (last->next != NULL)
        last = last->next;
    last->next = first;
    first->next = NULL;
    ft_printf("ra\n");
}

void rotate_b(t_stack_top **staks)
{
    t_list *first;
    t_list *last;

    if ((*staks)->b == NULL || (*staks)->b->next == NULL)
        return ;
    first = (*staks)->b;
    (*staks)->b = first->next;
    last = (*staks)->b;
    while (last->next != NULL)
        last = last->next;
    last->next = first;
    first->next = NULL;
    ft_printf("rb\n");
}

void rotate_anb(t_stack_top **staks)
{
    rotate_a(staks);
    rotate_b(staks);
    ft_printf("rr\n");
}

void reversey_ra(t_stack_top **staks)
{
    t_list *head;
    t_list *last;

    last = ft_lstlast((*staks)->a);
    if ((*staks)->a == NULL || (*staks)->a->next == NULL || !last)
        return ;
    head = (*staks)->a;
    while (head->next->next != NULL)
        head = head->next;
    head->next = NULL;
    last->next = (*staks)->a;
    (*staks)->a = last;
    ft_printf("rra\n");
}

void reversy_rb(t_stack_top **staks)
{
    t_list *head;
    t_list *last;

    last = ft_lstlast((*staks)->b);
    if ((*staks)->b == NULL || (*staks)->b->next == NULL || !last)
        return ;
    head = (*staks)->b;
    while (head->next->next != NULL)
        head = head->next;
    head->next = NULL;
    last->next = (*staks)->b;
    (*staks)->b = last;
    ft_printf("rrb\n");
}