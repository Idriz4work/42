/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:43:27 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/17 18:03:26 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// returns succes if valeu is just number (i % 2)
int	is_just(size_t i)
{
	if (i % 2 == 0)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	endresult;
	int	is_op;

	i = 0;
	endresult = 0;
	is_op = 1;
	while ((s[i] == ' ') || (s[i] >= 9 && s[i] <= '\r'))
		i++;
	if (s[i] == '+' || s[i] == '-' || s[i] == ' ')
	{
		if (s[i] == '-')
			is_op = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		endresult = endresult * 10 + s[i] - '0';
		i++;
	}
	return (is_op * endresult);
}

int	ft_isdigit(char *ce)
{
	int	i;

	i = 0;
	while (ce[i] != '\0')
	{
		if (!(ce[i] >= '0' && ce[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
