/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:40 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/18 20:22:11 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void process_values(t_stk_top *stak, int start)
{
	t_node	*original;
	int		i;

	original = stak->a; 
	i = 0;
	while (stak->a != NULL)
	{
		if (i == start)
			break ;
		i++;
		stak->a = stak->a->next;
	}
	while (stak->a != NULL && stak->a->next != NULL)
	{
		if (stak->a->content > stak->a->next->content)
			swap_a(stak);
		else
			merge_sort(&stak, 0, 0);
		stak->a = stak->a->next;
	}
	stak->a = original; 
}

int	check_sorted(t_stk_top *stak)
{
	int		index;
	t_node	*current;

	index = 0;
	current = stak->a; 
	while (current != NULL && current->next != NULL)
	{
		if (current->content < current->next->content)
		{
			index++;
			current = current->next;
			continue ;
		}
		return (index);
	}
	exit(1);
}

int	initialize_stack(t_stk_top **stak, t_node **nodes)
{
	*stak = malloc(sizeof(t_stk_top));
	if (!*stak)
		return (-1);
	*nodes = malloc(sizeof(t_node));
	if (!*nodes)
	{
		free(*stak);
		return (-1);
	}
	(*stak)->a = NULL;
	(*stak)->b = NULL;
	return (0);
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
	print_stack(stak, 'a');
	return (0);
}

int	handle_ops(char **argv)
{
	char	save;
	int		was_already;
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		was_already = 0;
		save = argv[i][0];
		j = i + 1;
		while (argv[j] != NULL)
			if (save == argv[j++][0])
				was_already++;
		if (ft_isdigit(save) == 0 || was_already > 0)
		{
			ft_printf("Error op\n");
			return (1);
		}
		i++;
	}
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
