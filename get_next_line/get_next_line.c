#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int freeler(char **s1, char **s2, char **s3)
{
    if (s1 && *s1)
    {
        free(*s1);
        *s1 = NULL;
    }
    if (s2 && *s2)
    {
        free(*s2);
        *s2 = NULL;
    }
    if (s3 && *s3)
    {
        free(*s3);
        *s3 = NULL;
    }
    return 1;
}

void update_holder(char **valueholder)
{
    int j = 0;
    int newline_pos = 0;
    char *newline = strchr(*valueholder, '\n');

    if (valueholder == NULL || *valueholder == NULL)
        return;

    if (newline == NULL)
    {
        (*valueholder)[0] = '\0';
        return;
    }

    newline_pos = newline - *valueholder + 1;
    while ((*valueholder)[newline_pos + j] != '\0')
    {
        (*valueholder)[j] = (*valueholder)[newline_pos + j];
        j++;
    }
    (*valueholder)[j] = '\0';
}

char *insert_line(char **line, char **valueholder)
{
    int i = 0;
    int j = 0;

    free(*line);
    *line = (char *)malloc(ft_strlen(*valueholder) + 1);
    if (*valueholder == NULL || *line == NULL)
        return NULL;

    while ((*valueholder)[i] != '\n' && (*valueholder)[i] != '\0')
    {
        (*line)[j] = (*valueholder)[i];
        i++;
        j++;
    }
    (*line)[j] = '\0';
    update_holder(valueholder);
    return *valueholder;
}

int read_file(char **valueholder,int bytes, int fd)
{
    char *temp;
    char *newline;

    temp = (char *)malloc(BUFF_SIZE + 1);
    if (temp == NULL)
        return -1;

    bytes = read(fd, temp, BUFF_SIZE);
    if (bytes <= 0)
    {
        free(temp);
        return bytes;
    }
    temp[bytes] = '\0';
    newline = ft_strjoin(*valueholder, temp);
    free(temp);
    free(*valueholder);
    *valueholder = newline;

    if (strchr(*valueholder, '\n'))
        return 1;

    return 2;
}

int get_next_line(const int fd, char **line)
{
    static char *valueholder = NULL;
    int result;

    if (fd == -1 || BUFF_SIZE <= 0 || !line)
        return -1;

    if (valueholder == NULL)
        valueholder = (char *)calloc(1, sizeof(char));

    while ((result = read_file(&valueholder,0, fd)) == 2)
        ;

    if (result == 1 || (result == 0 && *valueholder))
        valueholder = insert_line(line, &valueholder);

    if (valueholder == NULL || *valueholder == '\0')
    {
        freeler(&valueholder, NULL, NULL);
        return result;
    }

    return 1;
}


///////////////////// TESTING ///////////////////
// #include <stdio.h>
// int main() {
//     int fd;
//     char *line = NULL;
//     int lines_read = 0;
//     int i = 0;

//     fd = open("get_next_line.c", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return 1;
//     }

//     while (get_next_line(fd, &line) > 0)
//     {
//         printf("Line %d: %s\n", ++lines_read, line);
//         free(line);
//         line = NULL;
//         i++;
//     }
//     if (get_next_line(fd, &line) == -1)
//         printf("ERROR IN READING");
//     close(fd);
//     free(line);
//     return 0;
// }
//