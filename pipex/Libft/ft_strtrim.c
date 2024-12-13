/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:06:31 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:23:43 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_letter(char c, char const *set, int indexes)
{
	int	i;

	i = 0;
	while (i < indexes)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	calc_end(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen(s1) - 1;
	while (end >= 0 && check_letter(s1[end], set, ft_strlen(set)))
		end--;
	return (end);
}

int	calc_total_length(int end, int start, int total_len)
{
	if (end >= start)
		total_len = end - start + 1;
	else
		total_len = 0;
	return (total_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*trimmed;
	int		start;
	int		total_len;
	int		end;

	i = 0;
	start = 0;
	total_len = 0;
	while ((s1[start] != '\0') && (check_letter(s1[start], set,
				ft_strlen(set))))
		start++;
	end = calc_end(s1, set);
	total_len = calc_total_length(end, start, total_len);
	trimmed = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!trimmed)
		return (NULL);
	while (i < total_len)
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	trimmed[total_len] = '\0';
	return (trimmed);
}

// int main(void)
// {
//     char s[] = "something";
//     char set[] = "someiwrtehn";
//     printf("%s\n", ft_strtrim(s, set));
//     return (0);
// }