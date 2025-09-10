/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nssokols <nssokols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by nssokols          #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by nssokols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dispatch(const char *fmt, va_list *ap)
{
	if (*fmt == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	if (*fmt == 's')
		return (ft_print_str(va_arg(*ap, const char *)));
	if (*fmt == '%')
		return (ft_print_percent());
	if (*fmt == 'd' || *fmt == 'i')
		return (ft_print_signed(va_arg(*ap, int)));
	if (*fmt == 'u')
		return (ft_print_unsigned(va_arg(*ap, unsigned int)));
	if (*fmt == 'x')
		return (ft_print_hex_lower(va_arg(*ap, unsigned int)));
	if (*fmt == 'X')
		return (ft_print_hex_upper(va_arg(*ap, unsigned int)));
	if (*fmt == 'p')
		return (ft_print_pointer(va_arg(*ap, void *)));
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			total;
	int			wrote;

	if (!format)
		return (0);
	va_start(ap, format);
	total = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			wrote = dispatch(format + 1, &ap);
			if (wrote < 0)
				return (va_end(ap), -1);
			total += wrote;
			format += 2;
			continue ;
		}
		if (ft_write_str(format, 1) < 0)
			return (va_end(ap), -1);
		total += 1;
		format++;
	}
	va_end(ap);
	return (total);
}

