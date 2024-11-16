/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:13:27 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/16 22:20:17 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return (j);
}

int	remove_all(char **array, int j)
{
	while (j > 0)
		free(array[--j]);
	free(array);
	return (-1);
}

int	copy_one(char **array, int c, int i, char const *s)
{
	int	word_len;

	word_len = 0;
	while (s[i + word_len] != '\0' && s[i + word_len] != c)
		word_len++;
	*array = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!array)
		return (-1);
	return (word_len);
}

int	copyarray(char **array, char c, char const *s)
{
	int	i;
	int	j;
	int	counter_a;
	int	word_len;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		counter_a = 0;
		if (s[i] != c)
		{
			word_len = copy_one(&array[j], c, i, s);
			if (word_len == -1)
				return (remove_all(array, j));
			while (counter_a < word_len)
				array[j][counter_a++] = s[i++];
			array[j++][counter_a] = '\0';
		}
		else
			i++;
	}
	array[j] = NULL;
	return (word_len);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		result;

	if (!s)
		return (NULL);
	i = word_count(s, c);
	array = (char **)malloc(sizeof(char *) * (i + 1));
	if (!array)
		return (NULL);
	array[i] = NULL;
	result = copyarray(array, c, s);
	if (result == -1)
	{
		free(array);
		return (NULL);
	}
	return (array);
}
// int	test_single_split(void)
// {
// 	int		i;
// 	char	**result;
// 	char	test1[] = "I am back !";
// 	int		c;

// 	c = '!';
// 	i = 0;
// 	result = ft_split(test1, c);
// 	while (result[i] != NULL)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	if (i <= 1)
// 		return (1);
// 	return (0);
// }

// int	test_multiple_split(void)
// {
// 	int		i;
// 	char	**result;
// 	char	test1[] = "I am back !    ||[hellodes] ||";
// 	int		c;

// 	c = ' ';
// 	i = 0;
// 	result = ft_split(test1, c);
// 	while (result[i] != NULL)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	if (i <= 1)
// 		return (1);
// 	return (0);
// }

// // int	test_memory_split(void)
// // {
// // 	int		i;
// // 	char	**result;
// // 	char	test1[] = "I am back !";
// // 	int		c;

// // 	c = '!';
// // 	i = 0;
// // 	result = ft_split(test1, c);
// // 	while (result[i] != NULL)
// // 	{
// // 		printf("%s", result[i]);
// // 		i++;
// // 	}
// // 	if (i <= 1)
// // 		return (1);
// // 	return (0);
// // }

// int	main(void)
// {
// 	// char s[] = "Hello , my name is Ati, Nice to see you !";
// 	// char c = ',';
// 	char **result;
// 	int j;

// 	// result = ft_split(s, c);
// 	// int j = test_single_split();
// 	// if (j == 0)
// 	// {
// 	// 	printf("FAILED at first test\n");
// 	// 	return (0);
// 	// }
// 	// else
// 	// {
// 	// 	printf("\n");
// 	// }
// 	result = ft_split("hello!", ' ');
// 	// if (result == NULL)
// 	// {
// 	// 	printf("Memory allocation failed\n");
// 	// 	return (1);
// 	// }
// 	while (result[j] != NULL)
// 	{
// 		printf("%s", result[j]);
// 		j++;
// 	}
// 	j = 0;
// 	while (result[j] != NULL)
// 	{
// 		free(result[j]);
// 		j++;
// 	}
// 	free(result);
// 	return (0);
// }
