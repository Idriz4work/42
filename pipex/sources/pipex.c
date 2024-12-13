/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:36:20 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/13 05:53:22 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char **format)
{
	int		end_fd;
	int		index;

	index = 0;
	end_fd = dup(ft_atoi(format[argc - 1])); 

	while (index < argc - 1)
	{
		ft_printf("%s\n", format[index]);
		index++;
	}
	return index;
}


int	handle_multiple_cmd(char **format)
{
	int i;

	i = 0;
	return (i);
}

int	main(int argc, char **av)
{
	int	i;

	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1]) + 1) == 0)
		i = handle_multiple_cmd(av);
	i = pipex(argc, av);
	return (0);
}

