/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:40 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/25 08:41:01 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	handle_ops(void)
{
}

void push_swap(char **argv)
{
	ft_printf("%s",argv[0]);
	handle_ops();
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (argc < 2)
	{
		ft_printf("USAGE: %s <num1> <num2> ... Error\n",argv[0]);
		return -1;
	}
	while (argv[i] != NULL)
	{
		if (ft_isdigit(argv[i][j]) == 0)
		{
			ft_printf("%c: Error\n", argv[i][j]);
			return (1);
		}
	}
	push_swap(argv);
	return (0);
}
