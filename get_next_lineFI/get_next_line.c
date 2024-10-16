#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char *get_next_line(const int fd)
{
    static char *valueholder;
    static int first_iteration;
    char *line;
    int result;

    line = NULL;
    result = 0;
    if (fd < 0 || BUFF_SIZE <= 0)
        return NULL;

    if (!first_iteration)
    {
        valueholder = (char *)calloc(1, sizeof(char));
        if (!valueholder)
            return NULL;
        first_iteration = 1;
    }

    while ((result = read_file(&valueholder, 0, fd)) > 0)
        if (result == 1)
            break;

    if (result <= 0 && (!valueholder || !*valueholder))
    {
        freeler(&valueholder, NULL, NULL);
        return NULL;  // Indicate EOF or error
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
//     fd = open("gnlTester-master/files/42_with_nl", O_RDONLY);
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
