/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:13:27 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/19 20:32:55 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	inside_word;
	int	wordcounts;

	i = 0;
	inside_word = 0;
	wordcounts = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && inside_word == 0)
		{
			inside_word = 1;
			wordcounts++;
		}
		if (s[i] == c)
			inside_word = 0;
		i++;
	}
	return (wordcounts);
}

int	remove_all(char **array, int identificator)
{
	while (identificator > 0)
		free(array[--identificator]);
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
	if (!(*array))
		return (-1);
	return (word_len);
}

int	copyarray(char **array, char c, char const *s)
{
	int	i;
	int	identificator;
	int	counter_a;
	int	word_len;

	i = 0;
	identificator = 0;
	while (s[i] != '\0')
	{
		counter_a = 0;
		if (s[i] != c)
		{
			word_len = copy_one(&array[identificator], c, i, s);
			if (word_len == -1)
				return (remove_all(array, identificator));
			while (counter_a < word_len)
				array[identificator][counter_a++] = s[i++];
			array[identificator++][counter_a] = '\0';
		}
		else
			i++;
	}
	array[identificator] = NULL;
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
	if (array == NULL)
		return (NULL);
	array[i] = NULL;
	result = copyarray(array, c, s);
	if (result == -1 || array == NULL)
		return (NULL);
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
// 	char	**result;
// 	int		identificator;

// 	// char s[] = "Hello , my name is Ati, Nice to see you !";
// 	// char c = ',';
// 	// result = ft_split(s, c);
// 	// int identificator = test_single_split();
// 	// if (identificator == 0)
// 	// {
// 	// 	printf("FAILED at first test\n");
// 	// 	return (0);
// 	// }
// 	// else
// 	// {
// 	// 	printf("\n");
// 	// }
// 	result = ft_split("hello!", ' ');
// 	if (result == NULL)
// 	{
// 		printf("Memory allocation failed\n");
// 		return (1);
// 	}
// 	while (result[identificator] != NULL)
// 	{
// 		printf("%s", result[identificator]);
// 		identificator++;
// 	}
// 	identificator = 0;
// 	while (result[identificator] != NULL)
// 	{
// 		free(result[identificator]);
// 		identificator++;
// 	}
// 	free(result);
// 	return (0);
// }
