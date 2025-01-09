/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:42:15 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/07 15:05:43 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	int	i;

	i = '0';
	while (i != 58)
	{
		ft_putchar(i);
		i++;
	}
}
// int main()
// {
//     ft_print_alphabet();
//     return (0);
// }