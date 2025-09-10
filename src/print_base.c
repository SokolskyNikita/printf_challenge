/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ai <ai@student.42>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by ai                #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by ai               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_valid_base(const char *base)
{
	size_t	i;
	size_t	j;

	if (base == NULL)
		return (0);
	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_put_unbr_base_rec(
	unsigned long long n,
	const char *base,
	unsigned int blen)
{
	int		count;
	char	c;

	count = 0;
	if (n >= blen)
		count += ft_put_unbr_base_rec(n / blen, base, blen);
	c = base[n % blen];
	write(1, &c, 1);
	return (count + 1);
}

int	ft_put_unbr_base(unsigned long long n, const char *base)
{
	unsigned int	blen;

	if (!ft_is_valid_base(base))
		return (0);
	blen = (unsigned int)ft_strlen(base);
	return (ft_put_unbr_base_rec(n, base, blen));
}
