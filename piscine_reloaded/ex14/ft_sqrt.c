/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:46:06 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/07 15:08:17 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (nb);
	if (nb == 1)
		return (1);
	return (nb);
}

int	ft_sqrt(int nb)
{
	float	y;
	int		p;
	int		square;
	int		c;

	c = 0;
	p = 1;
	square = 1;
	if (!check(nb))
		return (0);
	while (nb > square)
	{
		p++;
		square = (p + 1) * (p + 1);
	}
	y = p;
	while (c < 10)
	{
		y = (nb / y + y) / 2;
		if (y * y == nb)
			return (y);
		c++;
	}
	return (y);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%i\n", ft_sqrt(2137523));
// }
