/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:19:33 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/12 09:50:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *s)
{
	int	i;
	int	endresult;
	int	is_op;

	i = 0;
	endresult = 0;
	is_op = 1;
	while (s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			is_op *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		endresult = endresult * 10 + s[i] - '0';
		i++;
	}
	return (is_op * endresult);
}
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	char s[] = "    +19046";
// 	printf("%i\n%i\n",ft_atoi(s),atoi(s));
// }