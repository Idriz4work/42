/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:18:06 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 20:36:20 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	condition_check(char **s, int index, int n)
{
	if (!*s)
		return (-1);
	if (n == 0)
	{
		(*s)[index++] = '0';
		(*s)[index] = '\0';
		return (0);
	}
	if (n < 0)
		(*s)[index++] = '-';
	return (index);
}

char	*reversy(char *s)
{
	in is_op;
	int	c;
	int	i;
	int	j;

	i = 0;
	c = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			is_op *= -1;
		i++;
	}
	if (is_op == 1)
		s[0] = '-';
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)malloc(12 * sizeof(char));
	i = condition_check(&s, i, n);
	if (i == -1)
		return (NULL);
	if (i == 0)
		return (s);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		s[i++] = n % 10 + '0';
		n /= 10;
	}
	s[i] = '\0';
	s = reversy(s);
	return (s);
}

int main()
{
	printf("my: %s\n",ft_itoa(-+-84028));
}