#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int koy(char **line,char *currentline,int j)
{
        // success in reading line
        return 1;
    // EOF is reached
    return 0;
}

char* save_value(char *currentline, int i)
{
    if (currentline[i] == '\n' || currentline[i] == EOF)
    {
        currentline[i] = '\0';
        return ft_strdup(currentline);
    }
    return currentline;
}

// save content of fd in curenline in 1 chunk (1024) 
// continue while indexbuffer is less than the bytes we read (either 1024 or less)
int get_next_line(const int fd, char **line)
{	
    char *holder;
    static char* temp;
    static char *currentline;
    static char *newholder;
    int i = 0, bytes;

    // Handle file error
    if (fd == -1)
    {
        free(holder);
        return -1;
    }
    
    while (1)
    {
        // Allocate memory
        holder = (char *)malloc(sizeof(char) * 10000000);
        // temp = (char *)malloc(sizeof(char) * BUFF_SIZE);
        currentline = (char *)malloc(sizeof(char) * 10000000);
        if (currentline == NULL || holder == NULL)
        {
            printf("mistake in memory allocation");
            return -1;  // Handle malloc failure
        }
        while ((bytes = read(fd,holder,BUFF_SIZE)) > 0)
        {            
            // free(holder);
            // free(currentline);
            i = 0;
            printf("in reading...");
            
            while (i < bytes)
            {
                if (currentline[i] == '\n' || holder[i] == '\n')
                {
                    temp = ft_strchr(holder,'\n');
                    if (temp != NULL)
                    {
                        printf("1");
                        newholder = ft_strjoin(currentline, temp);
                        
                        *line = ft_strdup(temp);  // Point to the new string
                        return 1;
                    }
                    if (temp == 0)
                    {
                        newholder = ft_strjoin(currentline, temp);
                        printf("0");
                        free(currentline);
                        *line = ft_strdup(temp);  // Point to the new string
                        return 0;
                    }
                }
            currentline[i] = holder[i];
            i++;
            }
        free(holder);
        holder = newholder;
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
        if (i == 2)
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
