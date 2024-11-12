/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:18:06 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/12 14:00:41 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*reversy(char *s)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	c = 0;
	j = ft_strlen(s) - 1;
	if (s[0] == '-')
		i++;
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

int	condition_check(char **s, int index, int n, int is_op)
{
	if (n == 0)
	{
		(*s)[index++] = '0';
		(*s)[index] = '\0';
		return (2);
	}
	if (n == -2147483648)
	{
		(*s) = ft_strdup("-2147483648");
		return (2);
	}
	if (is_op == 1)
		index++;
	return (index);
}

int	check_negative(char **s, int index, int n)
{
	int	is_op;

	is_op = 0;
	if (n < 0)
	{
		(*s)[index] = '-';
		is_op = 1;
	}
	return (is_op);
}

char	*ft_itoa(int n)
{
	int		is_op;
	int		i;
	char	*s;

	i = 0;
	s = (char *)malloc(14 * sizeof(char));
	if (!s)
		return (NULL);
	is_op = check_negative(&s, i, n);
	i = condition_check(&s, i, n, is_op);
	if (i == 2)
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

// #include "libft.h"
// int	main(void)
// {
// 	// printf("%d\n%d\n",INT_MIN,INT_MAX);
// 	printf("my: %s\n", ft_itoa(INT_MIN));
// }