

int		ft_toupper(char *ce)
{
	int i;
	i = 0;
	while (ce[i] != '\0')
	{
		if (ce[i] >= 'a' && ce[i] <= 'z')
			ce[i] -= 32;
		i++;
	}
	return ce;
}