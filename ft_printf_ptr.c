/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by student           #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_get_hex_char_lower(int n)
{
	if (n < 10)
		return (n + '0');
	return (n - 10 + 'a');
}

static int	ft_puthex_ptr(unsigned long n, int fd)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex_ptr(n / 16, fd);
	count += ft_putchar_fd(ft_get_hex_char_lower(n % 16), fd);
	return (count);
}

int	ft_putptr_fd(void *ptr, int fd)
{
	int				count;
	unsigned long	addr;

	count = 0;
	if (!ptr)
	{
		count += ft_putstr_fd("(nil)", fd);
		return (count);
	}
	addr = (unsigned long)ptr;
	count += ft_putstr_fd("0x", fd);
	count += ft_puthex_ptr(addr, fd);
	return (count);
}
