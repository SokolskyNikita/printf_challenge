/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nssokols <nssokols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by nssokols          #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by nssokols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_recursive(unsigned int n)
{
	int			count;
	char		c;

	count = 0;
	if (n >= 10)
	{
		count = print_recursive(n / 10);
		if (count < 0)
			return (-1);
	}
	c = '0' + (char)(n % 10);
	if (ft_write_str(&c, 1) < 0)
		return (-1);
	return (count + 1);
}

int				ft_print_unsigned(unsigned int n)
{
	return (print_recursive(n));
}

