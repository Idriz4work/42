#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int condition_check(char **lastvalue, char **temp, char **curentvalue, int fd)
{
    static int iteration;

    if (fd == -1)
        return -1;

    if (iteration == 0)
    {
        iteration = 1;
        *lastvalue = (char *)malloc(BUFF_SIZE);
        if (*lastvalue == NULL)
            return -1;  // Handle malloc failure
        **lastvalue = '\0';  // Initialize to empty string
    }

    // Allocate memory for temp
    *temp = (char *)malloc(BUFF_SIZE);
    if (*temp == NULL)
    {
        if (iteration == 1)
            free(*lastvalue);  // Free lastvalue if temp allocation fails
        return -1;  // Handle malloc failure
    }

    // Allocate memory for curentvalue
    *curentvalue = (char *)malloc(BUFF_SIZE);
    if (*curentvalue == NULL)
    {
        free(*temp);  // Free temp if curentvalue allocation fails
        if (iteration == 1)
            free(*lastvalue);  // Free lastvalue if curentvalue allocation fails
        return -1;  // Handle malloc failure
    }

    return 1;
}

char *reset_lastvalue(char **lastvalue)
{
    char *temp;
    // printf("RESET: [%s]\n",*lastvalue);
    int i = 0, j = 0;

    while ((*lastvalue)[i] != '\n')
        i++;
    
    i++;
    temp = (char *)malloc(ft_strlen(*lastvalue) - i + 1);
    if (!temp)
        return NULL;

    while ((*lastvalue)[i] != '\0')
    {
        temp[j] = (*lastvalue)[i];
        j++;
        i++;
    }
    temp[j] = '\0';
    free(*lastvalue);
    *lastvalue = ft_strdup(temp);
    free(temp);
    return *lastvalue;
}

char *newline_slicer(char **line,char **lastvalue,char **temp)
{
    char *rightline;
    int i, len_lastvalue,j;

    *lastvalue = ft_strjoin(*lastvalue,*temp);

    if (lastvalue == NULL || *lastvalue == NULL)
        return NULL;

    len_lastvalue = ft_strlen(*lastvalue);
    rightline = (char *)malloc(len_lastvalue + 1);
    if (!rightline)
        return NULL;

    i = j = 0;
    while (((*lastvalue)[i]) != '\n')
    {
        rightline[i] = ((*lastvalue)[i]);
        i++;
    }
    rightline[i] = '\0';
    *line = ft_strdup(rightline);
    // printf("LAST: [%s]\n",*lastvalue);
    return (reset_lastvalue(lastvalue));
}


// Updated get_next_line function
int get_next_line(const int fd, char **line)
{   
    static char *lastvalue;
    char *curentvalue;
    char *temp = NULL;
    int result,i,j,bytes, is_ok;

    i = j = 0;
    // Pass pointers to lastvalue andcurentvalue 
    is_ok = condition_check(&lastvalue,&temp,&curentvalue, fd);
    if (is_ok < 0)
        return -1;
    if (is_ok)
    {
        while (1)
        {
            bytes = read(fd, curentvalue, BUFF_SIZE);
            if (bytes > 0)
            {
                temp = strchr(curentvalue,'\n');
                if (temp)
                {
                    lastvalue = newline_slicer(line,&lastvalue,&temp);
                    return 1;
                }
                lastvalue = ft_strjoin(lastvalue,curentvalue);
            }
            else
            {
                temp = (char*)malloc(ft_strlen(lastvalue) + 1);
                while (1)
                {
                    while (lastvalue[i] != '\n')
                    {
                        temp[j] = lastvalue[i];
                        i++;
                        j++;
                    }
                    *line = ft_strdup(temp);
                    if (lastvalue[i] == '\n')
                        i++;
                    j = 0;
                }
                return 0;
            }
        }
    }
    // EOF file
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
        if (i == 10)
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
