/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nssokols <nssokols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by nssokols          #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by nssokols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_recursive(unsigned int n, const char *base)
{
	int			count;
	char		c;

	count = 0;
	if (n >= 16)
	{
		count = print_recursive(n / 16, base);
		if (count < 0)
			return (-1);
	}
	c = base[n % 16];
	if (ft_write_str(&c, 1) < 0)
		return (-1);
	return (count + 1);
}

int				ft_print_hex_lower(unsigned int n)
{
	return (print_recursive(n, "0123456789abcdef"));
}

int				ft_print_hex_upper(unsigned int n)
{
	return (print_recursive(n, "0123456789ABCDEF"));
}

