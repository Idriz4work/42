#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#ifdef BUFFER_SIZE
	;
#else
	;
#endif

// #define BUFF_SIZE 42

char *get_next_line(const int fd);
int	allocate_once(char **valueholder);
int read_file(char **valueholder, int bytes, int fd);
char *insert_line(char **valueholder);
void update_holder(char **valueholder);
int freeler(char **s1, char **s2, char **s3);

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void       *ft_calloc(size_t count, size_t size);
char *ft_strchr(char *s1, char c);
