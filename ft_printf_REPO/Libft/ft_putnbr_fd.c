/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:14:08 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/12 13:32:33 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printi_minti(char array[], int i, int fd)
{
	char	c;

	while (i >= 0)
	{
		c = array[i] + '0';
		write(fd, &c, 1);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	array[18];

	i = 0;
	if (fd == -1)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n > 9)
	{
		array[i++] = n % 10;
		n /= 10;
	}
	array[i] = n;
	printi_minti(array, i, fd);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("ft_te.txt", O_RDWR);
// 	ft_putnbr_fd(-2147483648, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(2147483647, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(0, fd);
// 	write(fd, "\n", 1);
// 	return (0);
// }
