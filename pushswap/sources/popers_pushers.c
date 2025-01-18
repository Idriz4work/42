/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popers_pushers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:32:38 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/18 20:25:16 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(int value, t_stk_top *stak)
{
	t_list	*newnode;

	newnode = ft_lstnew(malloc(sizeof(int)));
	if (!newnode || !newnode->content)
		return ;
	*(int *)(newnode->content) = value;
	ft_lstadd_front((t_list **)&stak->a, newnode);
}

void	push_b(int value, t_stk_top *stak)
{
	t_list	*newnode;

	newnode = ft_lstnew(malloc(sizeof(int)));
	if (!newnode || !newnode->content)
		return ;
	*(int *)(newnode->content) = value;
	ft_lstadd_front((t_list **)&stak->b, newnode);
}

void	pop_a(t_stk_top *stak)
{
	t_node	*temp;

	if (stak->a == NULL)
		return ;
	temp = stak->a;
	stak->a = temp->next;
	ft_lstdelone((t_list *)temp, free);
}

void	pop_b(t_stk_top *stak)
{
	t_node	*temp;

	if (stak->b == NULL)
		return ;
	temp = stak->b;
	stak->b = temp->next;
	ft_lstdelone((t_list *)temp, free);
}

void	print_stack(t_stk_top *stak, int a_b)
{
	t_node	*current;

	if (a_b == 'a')
	{
		current = stak->a;
		while (current != NULL)
		{
			ft_printf("%d ", *(int *)current->content);
			current = current->next;
		}
	}
	else
	{
		current = stak->b;
		while (current != NULL)
		{
			ft_printf("%d ", *(int *)current->content);
			current = current->next;
		}
	}
	ft_printf("\n");
}
