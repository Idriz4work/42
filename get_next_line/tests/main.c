//////////////////// TESTING ///////////////////

#include "./*"

#include <fcntl.h> // For open()
#include <stdio.h>
#include <unistd.h> // For close()

int	main(void)
{
	int		fd;
	char	*line;
	int		lines_read;

	lines_read = 0;
	// Open a file to test with
	fd = open("read_error.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	// Keep reading lines until EOF or an error occurs
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", lines_read, line);
		// printf("\n");
		lines_read++;
		free(line); // Free the line returned by get_next_line
	}
	// Check if the last call to get_next_line failed
	if (line == NULL && lines_read == 0)
		printf("No lines read or error occurred.\n");
	// Close the file
	close(fd);
	return (0);
}
