/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: iatilla- <iatilla-@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/11/06 17:00:17 by iatilla-         #+#    #+#             */
/*   Updated: 2024/11/06 17:00:17 by iatilla-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	allocateonce(int first_iteration, char **valueholder)
{
	if (!first_iteration)
	{
		*valueholder = (char *)ft_calloc(1, sizeof(char));
		if (!valueholder || !*valueholder)
			return (0);
		first_iteration = 1;
	}
	return (first_iteration);
}

void	update_holder(char **valueholder)
{
	char	*newline;
	int		j;
	int		newline_pos;

	if (!valueholder || !*valueholder)
		return ;
	newline = strchr(*valueholder, '\n');
	if (newline == NULL)
	{
		(*valueholder)[0] = '\0';
		return ;
	}
	newline_pos = (newline - *valueholder) + 1;
	j = 0;
	while ((*valueholder)[newline_pos + j] != '\0')
	{
		(*valueholder)[j] = (*valueholder)[newline_pos + j];
		j++;
	}
	(*valueholder)[j] = '\0';
}

char	*insert_line(char **valueholder)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	line = (char *)malloc(ft_strlen(*valueholder) + 1);
	if (line == NULL)
		return (NULL);
	if (strchr(*valueholder, '\n'))
	{
		while ((*valueholder)[i] != '\n' && (*valueholder)[i] != '\0')
			line[j++] = (*valueholder)[i++];
		line[j++] = (*valueholder)[i++];
		line[j] = '\0';
		update_holder(valueholder);
		return (line);
	}
	while ((*valueholder)[i] != '\0')
		line[j++] = (*valueholder)[i++];
	line[j] = '\0';
	free(valueholder);
	return (line);
}

int	read_file(char **valueholder, int bytes, int fd)
{
	char	*temp;
	char	*newline;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (temp == NULL)
		return (-1);
	bytes = read(fd, temp, BUFFER_SIZE);
	if (bytes > 0)
	{
		temp[bytes] = '\0';
		newline = ft_strjoin(*valueholder, temp);
		free(temp);
		free(*valueholder);
		*valueholder = newline;
		if (ft_strchr(*valueholder, '\n'))
			return (1);
	}
	if (bytes <= 0)
	{
		free(temp);
		return (bytes);
	}
	return (2);
}

char	*get_next_line(const int fd)
{
	static char	*			valueholder;
	static int					first_iteration;
	char	*										line;
	int												result;

	line = NULL;
	result = 0;
	first_iteration = allocateonce(first_iteration, &valueholder);
	if (fd < 0 || BUFFER_SIZE <= 0 || first_iteration == 0)
		return (NULL);
	result = read_file(&valueholder, 0, fd);
	while (result > 0)
		if (result == 1)
			break ;
	if (result <= 0 && (!valueholder || !*valueholder))
	{
		free(valueholder);
		return (NULL);
	}
	line = insert_line(&valueholder);
	return (line);
}

///////////////////// TESTING ///////////////////
// int	main(void)
// {
// 	int fd;
// 	char *line;
// 	int lines_read = 0;
// 	// Open a file to test with
// 	fd = open("get_next_line.c", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	// Keep reading lines until EOF or an error occurs
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Line %d: %s", lines_read, line);
// 		// printf("\n");
// 		lines_read++;
// 		free(line); // Free the line returned by get_next_line
// 	}
// 	// Check if the last call to get_next_line failed
// 	if (line == NULL && lines_read == 0)
// 		printf("No lines read or error occurred.\n");
// 	// Close the file
// 	close(fd);
// 	return (0);
// }
