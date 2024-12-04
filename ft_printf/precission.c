
#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	precission_stk(const char *format, int i, va_list args, int *bytes)
{
	while (!(format[i] >= 'A' && format[i] <= 'z'))
		i++;
	if (format[i] == 'i' || format[i] == 'd')
		i = int_handler(format, i, va_arg(args, int), bytes);
	if (format[i] == 'u')
		i = uns_handler(format, i, va_arg(args, unsigned int), bytes);
	if (format[i] == 'x')
		i = lowerhex_handler(format, i, va_arg(args, int), bytes);
	if (format[i] == 'X')
		i = upperhex_handler(format, i, va_arg(args, int), bytes);
	return (i);
}
