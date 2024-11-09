
int		ft_isdigit(char *ce)
{
	int i;

	i = 0;
	while (ce[i] != '\0')
	{
		if (!(ce[i] >= '0' && ce[i] <= '9'))
			return 1;
		i++;
	}
	return 0;
}