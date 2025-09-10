/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by student           #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[count])
	{
		write(fd, &s[count], 1);
		count++;
	}
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	int		count;
	long	nb;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr_fd(nb / 10, fd);
	count += ft_putchar_fd((nb % 10) + '0', fd);
	return (count);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr_fd(n / 10, fd);
	count += ft_putchar_fd((n % 10) + '0', fd);
	return (count);
}
