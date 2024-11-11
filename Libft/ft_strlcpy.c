/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:09:26 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 18:12:18 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *s1, char *s2, size_t size)
{
	int	i;
	int	retsize;

	i = 0;
	retsize = 0;
	while (s2[retsize] != '\0')
		retsize++;
	while (s2[i] != '\0' && size > 1)
	{
		s1[i] = s2[i];
		i++;
		size--;
	}
	s1[i] = '\0';
	return (retsize);
}
