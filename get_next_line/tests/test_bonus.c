#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "../get_next_line.h"
#include "../get_next_line.c"
#include "../get_next_line_utils.c"

void test1()
{
	printf("----------------MULTIPLE--------------\n");
	printf("");
	int fd = open("1char.txt",O_RDONLY);
	char *line1 = get_next_line(fd);
    printf("First line: [%s]\n", line1);
    free(line1);
	char *line2 = get_next_line(fd);
    printf("second line: [%s]\n", line2);
    free(line2);
}

int main()
{
	test1();
}
