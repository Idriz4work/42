/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:40 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/24 07:49:15 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	handle_edge_two(t_stack_top *stak)
{
	if ((stak->a->content < stak->a->next->content))
	{
		swap_a(stak);
		return ;
	}
}

void handle_edge_three(t_stack_top **stak)
{
    if ((*stak)->a->content > (*stak)->a->next->content
        && ((*stak)->a->next->content > (*stak)->a->next->next->content))
        return ;
    
    // Case 1: Highest element at first position
    if ((*stak)->a->content > (*stak)->a->next->content
        && (*stak)->a->content > (*stak)->a->next->next->content)
    {
        if ((*stak)->a->next->content < (*stak)->a->next->next->content)
            swap_a(*stak);
        else
            rotate_a(*stak);
    }
    // Case 2: Highest element at second position
    else if ((*stak)->a->next->content > (*stak)->a->content
        && (*stak)->a->next->content > (*stak)->a->next->next->content)
    {
        if ((*stak)->a->content < (*stak)->a->next->next->content)
        {
            rotate_a(*stak);
            return ;
        }   
        else
        {
            swap_a(*stak);
            rotate_a(*stak);
        }
    }
    // Case 3: Highest element at third position
    else if ((*stak)->a->next->next->content > (*stak)->a->content
        && (*stak)->a->next->next->content > (*stak)->a->next->content)
        reversey_ra(*stak);
}

void handle_edge_four(t_stack_top **stak)
{
    // Placeholder for 4-element list handling
    // Implement specific logic for sorting 4 elements
}

void process_values(t_stack_top **stak)
{
    int value = ft_lstsize((t_list *)(*stak)->a);
    
    if (value == 2)
        handle_edge_two(*stak);
    if (value == 3)
        handle_edge_three(stak);
    if (value == 4)
        handle_edge_four(stak);
    else
        osman_sort_algorithm(*stak);
}

int fill_stack(char **values)
{
    t_stack_top *stak;
    t_list *nodes;
    int i = 1;

    if (initialize_stack(&stak, &nodes) == -1)
    {
        ft_printf("Error\n");
        return (-1);
    }
    
    while (values[i] != NULL)
        push_a(ft_atoi(values[i++]), stak);
    process_values(&stak);
    print_stack(&stak, 'a');
    return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	if (handle_ops(argv) == -1)
		return (-2);
	if (fill_stack(argv) == -1)
		return (-3);
	return (0);
}
