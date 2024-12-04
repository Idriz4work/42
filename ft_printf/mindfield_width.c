
#include "ft_printf.h"
#include "ft_printf_bonus.h"

int int_handlermin_width(const char *format, int i, int value, int *bytes)
{
	int		in;
	char	buffer[20];
	long	placeholder;
	int		spaces;

	spaces = 0;
	placeholder = value;
	if (value == 0)
		spaces--;
	if (placeholder == -2147483648)
	{
		spaces -= 10;
		write(1, "-2", 2);
		*bytes += 2;
		placeholder = 147483648;
	}
	else if (value < 0)
	{
		write(1, "-", 1);
		*bytes += 1;
		placeholder *= -1;
		value *= -1;
		spaces -= 1;
	}
	while (format[i-- + 1] <= '%')
		;
	in = 0;
	while (format[i] >= '0' && format[i] <= '9')
		buffer[in++] = format[i++];
	buffer[in] = '\0';
	spaces += ft_atoi(buffer);
	in = 0;
	while (value > 0)
	{
		value /= 10;
		in++;
	}
	while (spaces-- > in)
	{
		write(1, " ", 1);
		*bytes += 1;
	}
	ft_putnbr_ext(placeholder, bytes);
	return (i + 1);
}

int str_handlermin_width(const char *format, int i, char *value, int *bytes)
{
	int		in;
	char	buffer[20];
	char*	placeholder;
	int		spaces;

	spaces = 0;
	placeholder = (char *)malloc(sizeof(char) + ft_strlen(value) + 1);
	if (!placeholder)
		return (-1);
	while (format[i - 1] != '%')
		i--;
	in = 0;
	while (format[i] >= '0' && format[i] <= '9')
		buffer[in++] = format[i++];
	buffer[in] = '\0';
	spaces += ft_atoi(buffer);
	in = ft_strlen(value);
	while (spaces-- > in)
	{
		write(1, " ", 1);
		*bytes += 1;
	}
	handle_strings(placeholder, bytes);
	return (i + 1);
}

int	fieldminwidth(const char *format, int i, va_list args, int *bytes)
{
	while (!(format[i] >= 'A' && format[i] <= 'z'))
		i++;
	if (format[i] == 'i' || format[i] == 'd')
		i = int_handlermin_width(format, i, va_arg(args, int), bytes);
	if (format[i] == 's')
		i = str_handlermin_width(format, i, va_arg(args, int), bytes);
	return (i);
}
