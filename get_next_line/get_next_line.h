// #include "libtft/."
#include "libtft/libtft.h"
// #include "libt_ft/ft_strdup.c"
#include <stdio.h>

#define BUFF_SIZE 1024 // 1024 = 1 chunk

int	get_next_line(const int fd, char **line);
char **fill_lines(const int fd, char **line, char *curentline, char *holder);