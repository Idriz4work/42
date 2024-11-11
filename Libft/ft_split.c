/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:13:27 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:26:39 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return (j);
}

char	**mem_allocate(char const *s, char c)
{
	int		c_counter;
	char	**array;

	c_counter = word_count(s, c);
	array = (char **)malloc(sizeof(char *) * (c_counter + 1));
	if (!array)
		return (NULL);
	array[0] = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!array[0])
	{
		free(array);
		return (NULL);
	}
	return (array);
}

int	copyarray(char **array, char c, char const *s)
{
	int	i;
	int	j;
	int	counter_a;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		counter_a = 0;
		if (s[i] != c)
		{
			array[j] = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
			if (!array[j])
				return (-1);
			while (s[i] && s[i] != c)
				array[j][counter_a++] = s[i++];
			array[j++][counter_a] = '\0';
		}
		else
			i++;
	}
	array[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		result;

	array = mem_allocate(s, c);
	if (!array)
		return (NULL);
	result = copyarray(array, c, s);
	if (result == -1)
		return (NULL);
	return (array);
}

// int main()
// {
//  char s[] = "Hello , my name is Ati, Nice to see you !";
//  char c = ',';
//  char **result;
//  int j = 0;

// 	result = ft_split(s, c);
//  if (result == NULL) {
//      printf("Memory allocation failed\n");
//      return (1);
//  }
//  while (result[j] != NULL)
//  {
//      printf("%s\n$", result[j]);
//      j++;
//  }
//  j = 0;
//  while (result[j] != NULL)
//  {
//      free(result[j]);
//      j++;
//  }
//  free(result);
//  return (0);
// }