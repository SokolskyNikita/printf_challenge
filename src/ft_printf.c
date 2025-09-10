/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ai <ai@student.42>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by ai                #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by ai               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_vprintf_core(const char *format, va_list *ap);
static int	ft_handle_conversion(char spec, va_list *ap);

static int	ft_vprintf_core(const char *format, va_list *ap)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			count += ft_handle_conversion(format[i], ap);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			written;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	written = ft_vprintf_core(format, &ap);
	va_end(ap);
	return (written);
}

static int	ft_handle_conversion(char spec, va_list *ap)
{
	if (spec == 'c')
		return (ft_print_char((char)va_arg(*ap, int)));
	if (spec == 's')
		return (ft_print_string(va_arg(*ap, const char *)));
	if (spec == 'p')
		return (ft_print_pointer(va_arg(*ap, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_print_signed(va_arg(*ap, int)));
	if (spec == 'u')
		return (ft_print_unsigned(va_arg(*ap, unsigned int)));
	if (spec == 'x')
		return (ft_print_hex(va_arg(*ap, unsigned int), 0));
	if (spec == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), 1));
	if (spec == '%')
		return (ft_print_percent());
	return (0);
}
