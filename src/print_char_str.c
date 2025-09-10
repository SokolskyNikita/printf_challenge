/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ai <ai@student.42>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by ai                #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by ai               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(const char *s)
{
	size_t	len;

	if (s == NULL)
	{
		len = ft_strlen(NULL_STR);
		write(1, NULL_STR, len);
		return ((int)len);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return ((int)len);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
