/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popers_pushers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:32:38 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/05 12:33:13 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stk_top	*push_a(int value, t_stk_top *stak)
{
	t_list	*newnode;

	newnode = NULL;
	newnode = ft_lstnew(malloc(sizeof(int)));
	if (!newnode || !newnode->content)
		return (stak);
	*(int *)(newnode->content) = value;
	ft_lstadd_front((t_list **)&stak->a, newnode);
	return (stak);
}

t_stk_top	*push_b(int value, t_stk_top *stak)
{
	t_list	*newnode;

	newnode = NULL;
	newnode = ft_lstnew(malloc(sizeof(int)));
	if (!newnode || !newnode->content)
		return (stak);
	*(int *)(newnode->content) = value;
	ft_lstadd_front((t_list **)&stak->b, newnode);
	return (stak);
}

t_stk_top	*pop_a(t_stk_top *stak)
{
	t_node	*temp;

	temp = NULL;
	if (stak->a == NULL)
		return (stak);
	temp = stak->a;
	stak->a = temp->next;
	ft_lstdelone((t_list *)temp, free);
	temp = NULL;
	return (stak);
}

t_stk_top	*pop_b(t_stk_top *stak)
{
	t_node	*temp;

	temp = NULL;
	if (stak->b == NULL)
		return (stak);
	temp = stak->b;
	stak->b = temp->next;
	ft_lstdelone((t_list *)temp, free);
	temp = NULL;
	return (stak);
}

void	print_stack(t_stk_top *stak, int a_b)
{
	t_node	*current;

	if (a_b == 1)
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
