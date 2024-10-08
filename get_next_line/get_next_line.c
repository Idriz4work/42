#include "get_next_line.h"

// save content of fd in curenline in 1 chunk (1024) 
// continue while indexbuffer is less than the bytes we read (either 1024 or less)
int get_next_line(const int fd, char **line)
{	
    static char *curentline = NULL;
    char *holder;
    
    // Allocate memory
    curentline = (char *)malloc(sizeof(char) * BUFF_SIZE);
    holder = (char *)malloc(sizeof(char) * 10000000); // this is a large allocation, adjust as necessary
    
    // Handle failed mallocs or file errors
    if (curentline == NULL || holder == NULL || fd == -1)
        return -1;

    // Fill the lines
    char **oldline = line;
    line = fill_lines(fd, line, curentline, holder);
    if (line == oldline)
    {
        // Free allocated memory
        free(curentline);
        free(holder);
        return 0;
    }
    // Free allocated memory
    free(curentline);
    free(holder);
    return 1;
}


int main()
{
    int fd;
    char *line = NULL;
    int lines_read = 0;

    fd = open("get_next_line.c", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while (get_next_line(fd, &line) > 0)
    {
        printf("Line %d: %s\n", ++lines_read, line);
        // free(line);
        // line = NULL;
    }
    close(fd);
    return 0;
}
