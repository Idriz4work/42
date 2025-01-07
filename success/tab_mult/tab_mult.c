#include <unistd.h>

// Convert string to integer
int ft_atoi(char *argv)
{
    int number = 0;
    int i = 0;
    int sign = 1;

    // Skip whitespace
    while (argv[i] == ' ' || (argv[i] >= '\t' && argv[i] <= '\r'))
        i++;
    // Handle sign
    if (argv[i] == '+' || argv[i] == '-')
    {
        if (argv[i] == '-')
            sign = -1;
        i++;
    }
    // Convert characters to integer
    while (argv[i] >= '0' && argv[i] <= '9')
    {
        number = number * 10 + (argv[i] - '0');
        i++;
    }
    return (number * sign);
}

// Write a single digit to output
void ft_putnbr(int n)
{
    if (n > 9)
        ft_putnbr(n / 10); // Recursively handle multi-digit numbers
    char c = (n % 10) + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i;
    int number;
    int result;

    if (argc == 2)
    {
        number = ft_atoi(argv[1]);
        i = 1;
        while (i <= 9) // Iterate from 1 to 9
        {
            result = number * i;

            ft_putnbr(i);          // Print multiplier
            write(1, " x ", 3);    // Print " x "
            ft_putnbr(number);     // Print the input number
            write(1, " = ", 3);    // Print " = "
            ft_putnbr(result);     // Print the result
            write(1, "\n", 1);     // New line
            i++;
        }
    }
    else
    {
        write(1, "\n", 1); // Print a newline if incorrect input
    }
    return (0);
}

