/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:09:05 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/23 13:25:41 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_putnbr_zero(int i, int *bytes)
{
	char	curent;
	int		written;

	if (i == -2147483648)
	{
		written = write(1, "2147483648", 11);
		*bytes += written;
		return ;
	}
	if (i < 0)
		i = -i;
	if (i >= 10)
		ft_putnbr_zero(i / 10, bytes);
	curent = (i % 10) + '0';
	written = write(1, &curent, 1);
	*bytes += written;
	return ;
}
