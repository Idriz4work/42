/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:40 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/04 05:37:59 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int handle_sorter(char **values)
{
	stack stak;
	int res;

	res = 0;
	return res;
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
