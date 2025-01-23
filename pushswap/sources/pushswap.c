/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:40 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/23 00:56:18 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	process_values(t_stk_top *stak, int start)
{
	int	i;

	i = 0;
	// while (stak->a != NULL)
	// {
	// 	if (i == start)
	// 		break ;
	// 	i++;
	// 	stak->a = stak->a->next;
	// }
	while (stak->a != NULL && stak->a->next != NULL)
	{
		osman_sort_algorithm(stak);
		print_stack(stak, 'a');
		i = check_sorted(stak);
		if (i == ft_lstsize((t_list *)stak))
			return ;
		else
			stak->a = stak->a->next;
		// print_stack(stak, 'b');
	}
}

int	fill_stack(char **values)
{
	t_stk_top	*stak;
	t_node		*nodes;
	int			i;
	int			starting_point;

	i = 1;
	if (initialize_stack(&stak, &nodes) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	while (values[i] != NULL)
		push_a(ft_atoi(values[i++]), stak);
	starting_point = check_sorted(stak);
	process_values(stak, starting_point);
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
