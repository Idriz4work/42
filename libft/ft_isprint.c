
int		ft_isprint(char *ce)
{
	int i;
	i = 0;
	while (ce[i] != '\0')
	{
		if ((ce[i] >= 0 && ce[i] <= 31) || ce[i] == 127)
			return 1;
		i++;
	}
	return 0;
}