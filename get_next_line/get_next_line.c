

#include "get_next_line.h"

int	allocate_once(char **valueholder)
{
	if (valueholder == NULL || *valueholder == NULL)
	{
		*valueholder = (char *)ft_calloc(sizeof(char),1);
		if (!valueholder || !*valueholder)
			return (-1);
	}
	return (1);
} 

// Updates the valueholder by removing the line that was read
void update_holder(char **valueholder)
{
    int j, newline_pos;
    char *newline;
    
    if (!valueholder || !*valueholder)
        return;
    newline = strchr(*valueholder, '\n');
    if (newline == NULL)
    {
        (*valueholder)[0] = '\0';
        return;
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

// Inserts a line into the line buffer
char *insert_line(char **valueholder)
{
    int i, j;
    char *line,*indicator;

    j = i = 0;
    line = (char *)malloc(ft_strlen(*valueholder) + 1);
    if (line == NULL)
        return NULL;
    indicator = strchr(*valueholder, '\n');
    if (indicator)
    {
        while ((*valueholder)[i] != '\n' && (*valueholder)[i] != '\0')
            line[j++] = (*valueholder)[i++];
        line[j++] = (*valueholder)[i++];
        line[j] = '\0';
        update_holder(valueholder);
        return line;
    }
    while ((*valueholder)[i] != '\0')
        line[j++] = (*valueholder)[i++];
    line[j] = '\0';
    freeler(valueholder, NULL, NULL);
    return line;
}

// Reads from the file and updates valueholder
int read_file(char **valueholder, int bytes, int fd)
{
    char *temp, *newline;

    temp = (char *)malloc(BUFFER_SIZE + 1);
    if (temp == NULL)
        return -1;

    bytes = read(fd, temp, BUFFER_SIZE);
    if (bytes > 0)
    {
        temp[bytes] = '\0';
        newline = ft_strjoin(*valueholder, temp);
        free(temp);
        free(*valueholder);
        *valueholder = newline;
        if (ft_strchr(*valueholder, '\n'))
            return 1;
    }
    if (bytes <= 0)
    {
        free(temp);
        return bytes;
    }
    return 2;
}

char *get_next_line(const int fd)
{
	static char	*valueholder;
	char		*line;
	int			result;

	line = NULL;
	if (valueholder == NULL)
		result = allocate_once(&valueholder);
	if (fd < 0 || BUFFER_SIZE <= 0 || result == -1)
		return (NULL);
   result = read_file(&valueholder, 0, fd);
			while (result > 0 && result != 1)
				result = read_file(&valueholder, 0, fd);

    if (result <= 0 && (!valueholder || !*valueholder))
    { 
        freeler(&valueholder, NULL, NULL);
        return NULL;
    }

    line = insert_line(&valueholder);
    return line;
}

///////////////////// TESTING ///////////////////
// #include <stdio.h>
// #include <fcntl.h> // For open()
// #include <unistd.h> // For close()
// int main(void)
// {
//     int fd;
//     char *line;
//     int lines_read = 0;
//     // Open a file to test with
//     fd = open("get_next_line.c", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return 1;
//     }
//     // Keep reading lines until EOF or an error occurs
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("Line %d: %s", lines_read, line);
//         // printf("\n");
//         lines_read++;
//         free(line); // Free the line returned by get_next_line
//     }
//     // Check if the last call to get_next_line failed
//     if (line == NULL && lines_read == 0)
//         printf("No lines read or error occurred.\n");
//     // Close the file
//     close(fd);
//     return 0;
// }

