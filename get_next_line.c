#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int freeler(char *s1, char *s2, char *s3)
{
    free(s1);
    free(s2);
    free(s3);
    return 1;
}

void    update_holder(char **valueholder, int i)
{
    int j;
    int newline_pos;
    char *newline;

    j = newline_pos = 0;
    newline = strchr(*valueholder, '\n');
    
    if (valueholder == NULL || *valueholder == NULL)
        return;

    if (newline == NULL)
    {
        (*valueholder)[0] = '\0';
        return;
    }

    newline_pos = newline - *valueholder + 1;  // +1 to include the newline itself
    while ((*valueholder)[newline_pos + j] != '\0')
    {
        (*valueholder)[j] = (*valueholder)[newline_pos + j];
        j++;
    }
    (*valueholder)[j] = '\0';
}

char    *insert_line(char **line, char **valueholder)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (valueholder == NULL || *valueholder == NULL)
        return NULL;
    
    *line = (char *)malloc(ft_strlen(*valueholder) + 1 * sizeof(char));
    while (((*valueholder)[i]) != '\n' && ((*valueholder)[i]) != '\0')
    {
        ((*line)[j]) = ((*valueholder)[i]);
        i++;
        j++;
    }
    ((*line)[j]) = '\0';
    update_holder(valueholder,i);
    return *valueholder;
}

// ----------------- FIX ------------------------ //
int read_file(char **valueholder, char **line, int bytes, int fd)
{
    char *temp; 
    char *newline;

    while (1)
    {
        temp = (char *)malloc(ft_strlen(*valueholder) + BUFF_SIZE + 1);
        if (temp == NULL)
            return -1;
        bytes = read(fd,temp, BUFF_SIZE);
        if (bytes <= 0)
            return -1;
        temp[bytes] = '\0';
        if (bytes > 0)
        {
            *valueholder = ft_strcat(*valueholder,temp);
            newline = strchr(temp, '\n');
            if (newline)
                return freeler(temp,NULL,NULL);
        }
    }
    return 0;
}

// ----------------- FIX ----------------------//
int get_next_line(const int fd, char **line)
{
    static char *valueholder;
    int result, bytes;

    if (fd == -1 || BUFF_SIZE <= 0)
        return -1;
    if (valueholder == NULL)
        valueholder = (char *)malloc(BUFF_SIZE + 1);
    bytes = 0;
    result = read_file(&valueholder, line, bytes, fd);
    if (result == 1)
    {
        valueholder = insert_line(line, &valueholder);
        return 1;
    }
    valueholder = insert_line(line,&valueholder);
    if (valueholder == NULL)
    {
        freeler(valueholder,NULL,NULL);
        return 0;
    }
    return 1;
}





///////////////////// TESTING ///////////////////
#include <stdio.h>
int main()
{
    int fd;
    char *line;
    int lines_read = 0;
    int i = 0;

    line = (char *)malloc(sizeof(char ) * 100000);
    if (line == NULL)
    {
        perror("Memory allocation failed");
        return 1;
    }

    fd = open("get_next_line.c", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while (get_next_line(fd, &line) > 0)
    {
        printf("Line %d: %s\n", ++lines_read, line);
        free(line);  // Free memory after use
        // if (i == 40)
        //     break;
        i++;
        line = NULL;
    }
    if (get_next_line(fd,&line) == -1)
        printf("ERROR IN READING");
    close(fd);
    free(line);
    return 0;
}
 