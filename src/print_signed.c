/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nssokols <nssokols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by nssokols          #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by nssokols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_recursive(unsigned int un)
{
	int			count;
	char		c;

	count = 0;
	if (un >= 10)
	{
		count = print_recursive(un / 10);
		if (count < 0)
			return (-1);
	}
	c = '0' + (char)(un % 10);
	if (ft_write_str(&c, 1) < 0)
		return (-1);
	return (count + 1);
}

int				ft_print_signed(int n)
{
	unsigned int	un;
	int				count;

	count = 0;
	if (n < 0)
	{
		if (ft_write_str("-", 1) < 0)
			return (-1);
		count++;
		un = (unsigned int)(-(long)n);
	}
	else
		un = (unsigned int)n;
	count += print_recursive(un);
	return (count);
}

