/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nssokols <nssokols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by nssokols          #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by nssokols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_recursive(unsigned long n)
{
	int			count;
	char		c;

	count = 0;
	if (n >= 16)
	{
		count = print_recursive(n / 16);
		if (count < 0)
			return (-1);
	}
	c = "0123456789abcdef"[n % 16];
	if (ft_write_str(&c, 1) < 0)
		return (-1);
	return (count + 1);
}

int				ft_print_pointer(void *p)
{
	unsigned long	addr;
	int				count;

	if (ft_write_str("0x", 2) < 0)
		return (-1);
	addr = (unsigned long)p;
	count = print_recursive(addr);
	if (count < 0)
		return (-1);
	return (count + 2);
}

