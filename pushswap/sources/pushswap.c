/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:40 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/05 15:53:45 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int	handle_sorter(char **values)
{
	t_stk_top	*stak;
	t_node		*nodes;
	int			res;
	int			i;

	i = 1;
	res = 0;
	if (initialize_stack(&stak, &nodes) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	while (values[i] != NULL)
		stak = push_a(ft_atoi(values[i++]), stak);
	// stak = pop_a(stak);
	// stak = pop_a(stak);
	stak = swap_a(stak);
	print_stack(stak,1);
	return (res);
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
			ft_printf("Error\n");
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
		return (-1);
	if (handle_sorter(argv) == -1)
		return (-1);
	return (0);
}
