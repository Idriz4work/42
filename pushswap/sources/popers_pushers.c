/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popers_pushers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:32:38 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/24 07:52:51 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(int value, t_stack_top **stak)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		exit(EXIT_FAILURE);
	newnode->content = value;
	newnode->next = (*stak)->a;
	(*stak)->a = newnode;
}

void	push_b(int value, t_stack_top **stak)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		exit(EXIT_FAILURE);
	newnode->content = value;
	newnode->next = (*stak)->b;
	(*stak)->b = newnode;
}

void	pop_a(t_stack_top **stak)
{
	t_list	*temp;

	if ((*stak)->a == NULL)
		return ;
	temp = (*stak)->a;
	(*stak)->a = temp->next;
	free(temp);
}

void	pop_b(t_stack_top **stak)
{
	t_list	*temp;

	if ((*stak)->b == NULL)
		return ;
	temp = (*stak)->b;
	(*stak)->b = temp->next;
	free(temp);
}

void	print_stack(t_stack_top **stak, int a_b)
{
	t_list	*current;

	if (a_b == 'a')
	{
		current = (*stak)->a;
		while (current != NULL)
		{
			ft_printf("%d ", current->content);
			current = current->next;
		}
	}
	else
	{
		current = (*stak)->b;
		while (current != NULL)
		{
			ft_printf("%d ", current->content);
			current = current->next;
		}
	}
	ft_printf("\n");
}
