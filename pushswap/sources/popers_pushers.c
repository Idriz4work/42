/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popers_pushers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:32:38 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/22 22:29:47 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(int value, t_stk_top *stak)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		exit(EXIT_FAILURE);
	newnode->contentt = value;
	newnode->next = stak->a;  
	stak->a = newnode;        
}

void	push_b(int value, t_stk_top *stak)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		exit(EXIT_FAILURE);
	newnode->contentt = value; 
	newnode->next = stak->b;   
	stak->b = newnode;         
}

void	pop_a(t_stk_top *stak)
{
	t_node	*temp;

	if (stak->a == NULL)
		return ;
	temp = stak->a;
	stak->a = temp->next;
	free(temp);	
}

void	pop_b(t_stk_top *stak)
{
	t_node	*temp;

	if (stak->b == NULL)
		return ;
	temp = stak->b;
	stak->b = temp->next;
	free(temp);	
}

void	print_stack(t_stk_top *stak, int a_b)
{
	t_node	*current;

	if (a_b == 'a')
	{
		current = stak->a;
		while (current != NULL)
		{
			ft_printf("%d ", current->contentt);
			current = current->next;
		}
	}
	else
	{
		current = stak->b;
		while (current != NULL)
		{
			ft_printf("%d ", current->contentt);
			current = current->next;
		}
	}
	ft_printf("\n");
}
