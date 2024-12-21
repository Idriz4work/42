/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:00:29 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/08 20:06:28 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	update_holder(char **valueholder)
{
	int		j;
	int		newline_pos;
	char	*newline;

	j = 0;
	if (!valueholder || !*valueholder)
	{
		free(*valueholder);
		return ;
	}
	newline = ft_strchr(*valueholder, '\n');
	if (!newline)
	{
		(*valueholder)[0] = '\0';
		return ;
	}
	newline_pos = (newline - *valueholder) + 1;
	while ((*valueholder)[newline_pos + j] != '\0')
	{
		(*valueholder)[j] = (*valueholder)[newline_pos + j];
		j++;
	}
	(*valueholder)[j] = '\0';
}

char	*insert_line(char **valueholder, int len)
{
	int		i;
	int		j;
	char	*line;
	char	*indicator;

	i = 0;
	j = 0;
	line = (char *)ft_calloc(len + 1, sizeof(char));
	if (!line || (!valueholder || !*valueholder))
		return (NULL);
	indicator = ft_strchr(*valueholder, '\n');
	if (indicator)
	{
		while ((*valueholder)[i] != '\n' && (*valueholder)[i] != '\0')
			line[j++] = (*valueholder)[i++];
		line[j++] = (*valueholder)[i++];
		update_holder(valueholder);
		return (line);
	}
	while ((*valueholder)[i] != '\0')
		line[j++] = (*valueholder)[i++];
	line[j] = '\0';
	free(*valueholder);
	*valueholder = NULL;
	return (line);
}

int	read_file(char **valueholder, int bytes, int fd)
{
	char	*temp;
	char	*newline;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (-1);
	bytes = read(fd, temp, BUFFER_SIZE);
	if (bytes > 0)
	{
		temp[bytes] = '\0';
		if (*valueholder)
		{
			newline = ft_strjoin(*valueholder, temp);
			free(*valueholder);
		}
		else
			newline = ft_strdup(temp);
		free(temp);
		if (!newline)
			return (-1);
		*valueholder = newline;
		if (ft_strchr(*valueholder, '\n') || bytes < BUFFER_SIZE)
			return (1);
	}
	return (readfile_helper(bytes, &temp));
}

char	*gnl_helper(char **value, int result)
{
	int	i;

	i = 0;
	if (result < 0)
	{
		free(*value);
		*value = NULL;
		return (NULL);
	}
	if ((value && *value) || result == 'c')
	{
		while ((*value)[i] != '\0')
			i++;
		return (insert_line(value, i));
	}
	return (NULL);
}

char	*get_next_line(const int fd)
{
	static char	*valueholder;
	char		*line;
	int			result;

	line = NULL;
	if (valueholder == NULL)
		valueholder = (char *)ft_calloc(1, sizeof(char));
	if (!valueholder || fd < 0 || BUFFER_SIZE <= 0)
		return (gnl_helper(&valueholder, -1));
	if (ft_strchr(valueholder, '\n'))
	{
		line = gnl_helper(&valueholder, 'c');
		return (line);
	}
	result = read_file(&valueholder, 0, fd);
	while (result == 2)
		result = read_file(&valueholder, 0, fd);
	if ((valueholder && *valueholder) || result < 0)
		return (gnl_helper(&valueholder, result));
	free(valueholder);
	valueholder = NULL;
	return (NULL);
}

// int	main(void)
// {
// 	int i;
// 	i = 0;
// 	const int fd = open("readerror.txt", O_RDONLY);
// 	char *line[3];
// 	while (line[i] != NULL)
// 	{
// 		line[i] = get_next_line(fd);
// 		printf("result of line[%i]: %s\n", i, line[i]);
// 		i++;
// 	}
// 	if (line[i] != NULL)
// 	{
// 		printf("MISTAKE AT line[%i]: %s", i, line[i]);
// 		return (0);
// 	}
// 	return (0);
// }