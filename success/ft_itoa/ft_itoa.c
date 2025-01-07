// #include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char	*str;
	long	temp;

	long n = nbr;                 // Use long to handle INT_MIN case
	int len = 0;
	if (nbr <= 0)
		len = 1;
	temp = n;
	// Calculate the number of digits
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	// Allocate memory for string and null-terminator
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0'; // Null-terminate the string
	if (n < 0)
	{
		str[0] = '-'; // Add negative sign
		n = -n;       // Make n positive for digit extraction
	}
	else if (n == 0) // Handle the special case for 0
	{
		str[0] = '0';
	}
	// Fill the string from the back
	while (n != 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

// int	main(void)
// {
// 	char	*s;

// 	s = ft_itoa(324);
// 	printf("%s\n", s);
// }
