
char *ft_tolower(char *ce)
{
	int i;
	i = 0;
	while (ce[i] != '\0')
	{
		if (ce[i] >= 'A' && ce[i] <= 'Z')
			ce[i] += 32;
		i++;
	}
	return ce;
}