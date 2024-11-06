#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define IFDEF BUFFER_SIZE

#define ENDIF

char	*get_next_line(const int fd);
int		allocateonce(int first_iteration, char **valueholder);
int		read_file(char **valueholder, int bytes, int fd);
char	*insert_line(char **valueholder);
void	update_holder(char **valueholder);
int		freeler(char **s1, char **s2, char **s3);

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *s1, char c);
