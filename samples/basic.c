/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by student           #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	main(void)
{
	int	count;

	ft_printf("=== Basic ft_printf Examples ===\n\n");
	
	count = ft_printf("1. Simple text: Hello, World!\n");
	ft_printf("   (returned %d)\n\n", count);
	
	count = ft_printf("2. Character: %c\n", 'A');
	ft_printf("   (returned %d)\n\n", count);
	
	count = ft_printf("3. String: %s\n", "42 School");
	ft_printf("   (returned %d)\n\n", count);
	
	count = ft_printf("4. Decimal: %d\n", -42);
	ft_printf("   (returned %d)\n\n", count);
	
	count = ft_printf("5. Integer: %i\n", 2147483647);
	ft_printf("   (returned %d)\n\n", count);
	
	count = ft_printf("6. Unsigned: %u\n", 4294967295u);
	ft_printf("   (returned %d)\n\n", count);
	
	count = ft_printf("7. Hex lower: %x\n", 255);
	ft_printf("   (returned %d)\n\n", count);
	
	count = ft_printf("8. Hex upper: %X\n", 255);
	ft_printf("   (returned %d)\n\n", count);
	
	count = ft_printf("9. Pointer: %p\n", &count);
	ft_printf("   (returned %d)\n\n", count);
	
	count = ft_printf("10. Percent: 100%%\n");
	ft_printf("    (returned %d)\n\n", count);
	
	count = ft_printf("11. Mixed: %c %s %d %x %%\n", 'X', "test", 42, 42);
	ft_printf("    (returned %d)\n\n", count);
	
	return (0);
}