
int ft_atoi(char *s)
{
	int i, endresult, is_op;

	i = endresult = 0;
	is_op = 1;
	while (s[i] == 32)
		i++;
	while (s[i] == '+' || s[i] == '-')	
	{
		if (s[i] == '-')
			is_op *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		endresult = endresult * 10 + s[i] - '0';
		i++;
	}
	return is_op * endresult;
}
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	char s[] = "  --+-219046";
// 	printf("%i\n%i",ft_atoi(s),atoi(s));
// }