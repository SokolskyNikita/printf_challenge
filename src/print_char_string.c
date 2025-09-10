/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nssokols <nssokols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by nssokols          #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by nssokols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_print_char(int c)
{
	char		ch;

	ch = (char)c;
	if (ft_write_str(&ch, 1) < 0)
		return (-1);
	return (1);
}

int				ft_print_str(const char *s)
{
	const char	*null_s;
	size_t		len;

	if (!s)
	{
		null_s = "(null)";
		if (ft_write_str(null_s, 6) < 0)
			return (-1);
		return (6);
	}
	len = ft_strlen_safe(s);
	if (ft_write_str(s, len) < 0)
		return (-1);
	return ((int)len);
}

int				ft_print_percent(void)
{
	if (ft_write_str("%", 1) < 0)
		return (-1);
	return (1);
}

