/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:13:48 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/12 11:17:38 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd == -1)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int main()
// {
// 	int fd;
// 	fd = -1;
// 	char ar[] = "hello";
// 	ft_putstr_fd(ar, fd);
// 	write(fd, "\n", 1);
// 	ft_putstr_fd(ar, fd);
// 	write(fd, "\n", 1);
// 	ft_putstr_fd(ar, fd);
// 	write(fd, "\n", 1);
// 	return (0);
// }
