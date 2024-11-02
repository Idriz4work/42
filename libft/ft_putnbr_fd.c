#include "libft.h"

void printi_minti(char array[], int i, int fd)
{
	char c;
	while (i >= 0)
	{
		c = array[i] + '0';
		write(fd, &c, 1);
		i--;
	}
}

void ft_putnbr_fd(int n, int fd)
{
	int i;
	char array[18];

	i = 0;
	if (n == 2147483648)
	{
		write(fd, "-2147483648", 12);
		return;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n > 9)
	{
		array[i] = n % 10;
		n /= 10;
		i++;
	}
	array[i] = n;
	printi_minti(array, i, fd);
}

// int main()
// {
// 	int fd;
// 	fd = 1; // Standard output for testing
// 	ft_putnbr_fd(12345, fd);
// 	write(fd, "\n", 1); // Newline for clarity
// 	ft_putnbr_fd(-6789, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(0, fd);
// 	write(fd, "\n", 1);
// 	return 0;
// }
