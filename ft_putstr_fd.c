
void ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i++] != '\0' && fd != 1)
		write(fd,&s[i],1);
	write(fd,&s[i],1);
}