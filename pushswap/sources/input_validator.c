/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:55:49 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/24 03:27:33 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_sorted(t_stack_top *stak)
{
	int		index;
	t_list	*current;

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

int	initialize_stack(t_stack_top **stak, t_list **nodes)
{
	*stak = malloc(sizeof(t_stack_top));
	if (!*stak)
		return (-1);
	*nodes = malloc(sizeof(t_list));
	if (!*nodes)
	{
		free(*stak);
		return (-1);
	}
	(*stak)->a = NULL;
	(*stak)->b = NULL;
	return (0);
}

// Helper function to check if a string is a valid number
static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	handle_ops(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_strncmp(argv[i], argv[j], 20) == 0)
			{
				ft_printf("Error op\n");
				return (-1);
			}
			j++;
		}
		if (!is_valid_number(argv[i]))
		{
			ft_printf("Error op\n");
			return (-1);
		}
		i++;
	}
	return (0);
}
