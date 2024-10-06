#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char *curentline;
	char *holder;
	int i, j;
	i = j = 0;
	curentline = (char *)malloc(sizeof(char) * 9000);
	if (curentline == NULL)
		return -1;
	while(read(fd,curentline,BUFF_SIZE) > 0)
	{
		if (curentline[j] != '\n')
		{
			line[i][j] = curentline[j]; //= ft_strdup(curentline);
			j++;
			printf("%c\n",line[i][j]);
			continue;
		}
		else{
			printf("%s\n",line[i]);
			i++;
			j++;
		}
	}
 return 1;
}

int main()
{
    int fd;
    char *line;

    // Open the file in read-only mode
    fd = open("get_next_line.h", O_RDONLY); // Replace "test.txt" with the file you want to read
    if (fd == -1)
    {
        perror("Error opening file");
    }

    // Call your get_next_line function
    if (get_next_line(fd, &line) == -1)
    {
        printf("Error reading line\n");
        close(fd);
        return 1;
    }

    // Print the line read (assuming the function fills 'line' correctly)
    printf("Line: %s\n", line);

    // Close the file
    close(fd);

    return 0;
}
