
int		ft_isalpha(char *ce)
{
	int i;
	i = 0;
	while (ce[i] != '\0')
	{
		if (!(ce[i] >= 'a' && ce[i] <= 'z')
		 || (ce[i] >= 'A' && ce[i] <= 'Z'))
			return 1;
		i++;
	}
	return 0;
}