#include "get_next_line.h"

char **fill_lines(const int fd, char **line, char *curentline, char *holder)
{
    int i = 0, j = 0, indexbuffer, bytes;
    char c;
    while ((bytes = read(fd, curentline, BUFF_SIZE)) > 0) // reading from the file descriptor
    {
        indexbuffer = 0;
        while (indexbuffer < bytes)
        {
            if (c == 'Z')
                return line;
            if (curentline[indexbuffer] == EOF)
            {
                // Free allocated memory
                free(curentline);
                free(holder);
                return 0;
            }
            
            if (curentline[indexbuffer+1] == '\n')
            {
                holder[i] = '\0'; 
                line[j] = strdup(holder); 
                printf("%d: %s\n", j, line[j]); 
                j++; 
                i = 0; 
                indexbuffer++; 
                c = 'Z';
                continue; 
            }
            holder[i] = curentline[indexbuffer]; // store character in holder
            indexbuffer++;
            i++;
        }
    }

    // if (i > 0) // if there's anything left in holder after the loop
    // {
    //     holder[i] = '\0';
    //     line[j] = strdup(holder);
    //     printf("%d: %s\n", j, line[j]); // print the last line
    // }

    return line; // return the filled array of lines
}
