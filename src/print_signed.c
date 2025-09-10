/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ai <ai@student.42>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by ai                #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by ai               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_rec(long n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_rec(n / 10);
	c = (char)('0' + (n % 10));
	write(1, &c, 1);
	return (count + 1);
}

int	ft_print_signed(int n)
{
	long	ln;
	int		count;

	ln = (long)n;
	count = 0;
	if (ln < 0)
	{
		write(1, "-", 1);
		count++;
		ln = -ln;
	}
	count += ft_putnbr_rec(ln);
	return (count);
}
