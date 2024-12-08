

#include "../get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int i;
	i = 0;
	const int fd = open("readerror.txt", O_RDONLY);
	char *line[3];
	while (line[i] != NULL)
	{
		line[i] = get_next_line(fd);
		printf("result of line[%i]: %s\n",i, line[i]);
		i++;
	}
	if (line[i] != NULL)
	{
		printf("MISTAKE AT line[%i]: %s",i, line[i]);
		return (0);
	}
	return 0;
}