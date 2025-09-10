/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by student           #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_get_hex_char(int n, char format)
{
	if (n < 10)
		return (n + '0');
	if (format == 'x')
		return (n - 10 + 'a');
	return (n - 10 + 'A');
}

int	ft_puthex_fd(unsigned int n, int fd, char format)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex_fd(n / 16, fd, format);
	count += ft_putchar_fd(ft_get_hex_char(n % 16, format), fd);
	return (count);
}
