/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:26:58 by marvin            #+#    #+#             */
/*   Updated: 2024/12/02 19:03:26 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	check_conditionpt2(const char *format, int i, va_list args, int *bytes)
{
	t_datatype	datatype;
	int			written;

	if (format[i] == 'i' || format[i] == 'd')
	{
		datatype.inte = va_arg(args, int);
		ft_putnbr_ext(datatype.inte, bytes);
		i++;
	}
	else if (format[i] == 'c')
	{
		datatype.ch = va_arg(args, int);
		written = write(1, &datatype.ch, 1);
		*bytes += written;
		i++;
	}
	else if (format[i] == 'u' || format[i - 1] == 'u')
	{
		datatype.uns = va_arg(args, unsigned int);
		ft_putnbr_uns(datatype.uns, bytes);
		i++;
	}
	return (i);
}

int	check_conditions(const char *format, int i, va_list args, int *bytes)
{
	t_datatype	datatype;

	i++;
	if (format[i] == 's')
	{
		handle_strings(va_arg(args, char *), bytes);
		i++;
	}
	else if (format[i] == 'p')
	{
		put_pointer(va_arg(args, void *), bytes);
		i++;
	}
	else if (format[i] == 'x' || format[i] == 'X')
	{
		datatype.hex = va_arg(args, unsigned int);
		if (format[i] == 'x')
			print_hex(datatype.hex, 1, bytes);
		else
			print_hex(datatype.hex, 2, bytes);
		i++;
	}
	else
		i = check_conditionpt2(format, i, args, bytes);
	return (i);
}

int	handle_percent(const char *format, int *i, int *bytes)
{
	int	written;
	int	j;

	j = 0;
	if (format[*i + 1] == '%')
	{
		(*i) += 2;
		written = write(1, "%", 1);
		*bytes += written;
		j = -1;
	}
	else if ((!(format[*i + 1] >= 'a' && format[*i + 1] <= 'z')) && (!(format[*i
				+ 1] >= 'A' && format[*i + 1] <= 'Z')))
	{
		if (!(format[*i + 1] >= '0' && format[*i + 1] <= '9'))
		{
			written = write(1, "%", 1);
			*bytes += written;
			(*i)++;
			j = -1;
		}
	}
	return (j);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		bytes;
	va_list	args;
	int		j;

	va_start(args, format);
	i = 0;
	bytes = 0;
	while (format[i] != '\0' && i < (int)ft_strlen(format))
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '0' || format[i + 1] == '#' || 
			format[i + 1] == ' ' || format[i + 1] == '-' || format[i + 1] == '.')
				i = handle_flags(format, i, args, &bytes);
			else
			{
				j = handle_percent(format, &i, &bytes);
				if (j == -1)
					continue ;
				i = check_conditions(format, i, args, &bytes);
				continue ;
			}
		}
		write(1, &format[i], 1);
		bytes += 1;
		i++;
	}
	if (i > (int)ft_strlen(format))
		bytes -= i - (int)ft_strlen(format);
	va_end(args);
	return (bytes);
}

// int main(void)
// {
// 	ft_printf("%d\n",032);
// 	printf("%d\n",032);

// ft_printf("%s\n","yo whaqt up dbe");
// printf("%s\n","yo whaqt up");

// ft_printf("%s\n\\r","yo whaqt up");
// printf("%s\n\\r","yo whaqt up");

// ft_printf("%s\n\\r","yo whaqt up");
// printf("%s\n\\r","yo whaqt up");
// }
