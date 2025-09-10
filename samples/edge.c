/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by student           #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	count;

	ft_printf("=== Edge Cases for ft_printf ===\n\n");
	
	ft_printf("1. INT_MIN and INT_MAX:\n");
	count = ft_printf("   MIN: %d, MAX: %d\n", INT_MIN, INT_MAX);
	ft_printf("   (returned %d)\n\n", count);
	
	ft_printf("2. Zero values:\n");
	count = ft_printf("   %d %i %u %x %X\n", 0, 0, 0u, 0u, 0u);
	ft_printf("   (returned %d)\n\n", count);
	
	ft_printf("3. NULL pointer:\n");
	count = ft_printf("   %p\n", NULL);
	ft_printf("   (returned %d)\n\n", count);
	
	ft_printf("4. NULL string:\n");
	count = ft_printf("   %s\n", (char *)NULL);
	ft_printf("   (returned %d)\n\n", count);
	
	ft_printf("5. Empty string:\n");
	count = ft_printf("   '%s'\n", "");
	ft_printf("   (returned %d)\n\n", count);
	
	ft_printf("6. UINT_MAX:\n");
	count = ft_printf("   %u\n", 4294967295u);
	ft_printf("   (returned %d)\n\n", count);
	
	ft_printf("7. Hex values (beef/BEEF):\n");
	count = ft_printf("   %x %X\n", 48879, 48879);
	ft_printf("   (returned %d)\n\n", count);
	
	ft_printf("8. Multiple percent signs:\n");
	count = ft_printf("   %%%% = %%\n");
	ft_printf("   (returned %d)\n\n", count);
	
	ft_printf("9. Long string:\n");
	count = ft_printf("   %s\n", 
		"This is a very long string to test if ft_printf handles "
		"long strings correctly without any issues.");
	ft_printf("   (returned %d)\n\n", count);
	
	ft_printf("10. Negative numbers:\n");
	count = ft_printf("   %d %i\n", -1, -2147483648);
	ft_printf("   (returned %d)\n\n", count);
	
	return (0);
}