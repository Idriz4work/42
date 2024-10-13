#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

void freeall(char *temp, char *valueholder, int indicator)
{
    if (indicator == 0)
        free(temp);
    if (indicator == 1)
    {
        free(valueholder);
        free(temp);
    }
    printf("\n--------[FREED MEMORY]---------\n");
}

char *reset_valueholder(char **valueholder)
{
    char *newline_pos, *remaining;

    newline_pos = strchr(*valueholder, '\n');
    if (newline_pos)
    {
        remaining = ft_strdup(newline_pos + 1);  // Keep everything after '\n'
        free(*valueholder);  // Free the old buffer
        *valueholder = remaining;  // Set the remaining part as the new buffer
    }
    return *valueholder;
}

char *insert_line(char **line, char **valueholder)
{
    char *temp = NULL;
    int i, len_lastvalue;

    i = 0;
    temp = ft_strdup(*valueholder);  // Initialize temp here with a copy of valueholder
    *valueholder = ft_strjoin(*valueholder, temp);

    if (valueholder == NULL || *valueholder == NULL)
        return NULL;

    len_lastvalue = ft_strlen(*valueholder);
    *line = (char *)malloc(len_lastvalue + 1);

    while (((*valueholder)[i]) != '\n' && ((*valueholder)[i]) != '\0')
    {
        ((*line)[i]) = ((*valueholder)[i]);
        i++;
    }
    ((*line)[i]) = '\0';

    free(temp);  // Free temp after use
    return *valueholder;
}

int read_file(char **valueholder, char **line, int bytes, int fd)
{
    char *temp; 

    bytes = read(fd, *valueholder, BUFF_SIZE);
    valueholder[bytes + 1] = '\0';
    if (bytes > 0)
    {
        temp = strchr(*valueholder, '\n');
        if (temp)
        {
            *valueholder = insert_line(line, valueholder);
            *valueholder = reset_valueholder(valueholder);
            free(temp);  // Free temp after use
            return 1;
        }
        *valueholder = ft_strjoin(*valueholder,temp);
    }
    temp = ft_strcpy(temp,*valueholder);

    if (bytes == 0)
    {
        free(temp);  // Free temp in case it was used
        return 0;
    }
    free(temp);  
    return -1;
}

int get_next_line(const int fd, char **line)
{
    static char *valueholder;
    int result, bytes;

    if (fd == -1 || BUFF_SIZE <= 0)
        return -1;

    if (!valueholder)
        valueholder = (char *)malloc(BUFF_SIZE + 1);

    bytes = 0;
    result = read_file(&valueholder, line, bytes, fd);
    while (result == -1)
    {
        result = read_file(&valueholder, line, bytes, fd);
        if (result == 1)
            return 1;
        if (result == 0)
            break;
    }

    insert_line(line, &valueholder);  // Call without temp
    freeall(NULL, valueholder, 1);  // freeall with temp = NULL (not used here)
    return 0;
}


#include <stdio.h>
int main()
{
    int fd;
    char *line;
    int lines_read = 0;
    int i = 0;

    // Allocate memory for the line pointer array
    line = (char *)malloc(sizeof(char ) * 100);  // Allocating space for 100 lines (adjust as necessary)
    if (line == NULL)
    {
        perror("Memory allocation failed");
        return 1;
    }

    // Open the file to read
    fd = open("get_next_line.c", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Read lines one by one using get_next_line
    while (get_next_line(fd, &line) > 0)
    {
        printf("Line %d: %s\n", ++lines_read, line);
        // free(line);  // Free memory after use
        if (i == 5)
            break;
        i++;
        // line = NULL;
    }
    if (get_next_line(fd,&line) == -1)
        printf("ERROR IN READING");

    // Close the file descriptor
    close(fd);

    // Free memory for the line array
    free(line);

    return 0;
}
 