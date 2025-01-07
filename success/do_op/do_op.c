#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	num1;
	int	op;
	int	num2;

	i = 0;
	if (argc == 4)
	{
		num1 = atoi(argv[1]);
		op = argv[2][0];
		num2 = atoi(argv[3]);
		if (op == '*')
			printf("%i\n", num1 * num2);
		else if (op == '+')
			printf("%i\n",num1 + num2);
		else if (op == '-')
			printf("%i\n", num1 - num2);
		else if (op == '%')
			printf("%i\n", num1 % num2);
		else if (op == '/')
			printf("%i\n", num1 / num2);
	}
	else
		write(1, "\n", 1);
}
