/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nssokols <nssokols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by nssokols          #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by nssokols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_strlen_safe(const char *s)
{
	const char	*p;

	if (!s)
		return (0);
	p = s;
	while (*p)
		p++;
	return ((size_t)(p - s));
}

int				ft_write_str(const char *s, size_t len)
{
	size_t		written;
	ssize_t		w;

	written = 0;
	while (written < len)
	{
		w = write(1, s + written, len - written);
		if (w < 0)
			return (-1);
		written += (size_t)w;
	}
	return ((int)len);
}

