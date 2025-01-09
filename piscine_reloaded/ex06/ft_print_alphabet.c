/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:42:32 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/07 15:32:54 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	int	i;

	i = 'a';
	while (i != 123)
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
