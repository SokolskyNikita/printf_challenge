/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by student           #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_conversion(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		count = ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		count = ft_putptr_fd(va_arg(args, void *), 1);
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		count = ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x' || c == 'X')
		count = ft_puthex_fd(va_arg(args, unsigned int), 1, c);
	else if (c == '%')
		count = ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handle_conversion(format[i], args);
		}
		else
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
