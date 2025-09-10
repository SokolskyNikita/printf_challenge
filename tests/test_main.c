/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by student           #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "../ft_printf.h"

static void	test_basic(void)
{
	int	ret1;
	int	ret2;

	printf("=== Basic Tests ===\n");
	
	printf("Test 1 - Plain text:\n");
	ret1 = printf("Hello World!\n");
	ret2 = ft_printf("Hello World!\n");
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);
	
	printf("Test 2 - Character:\n");
	ret1 = printf("Char: %c\n", 'A');
	ret2 = ft_printf("Char: %c\n", 'A');
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);
	
	printf("Test 3 - String:\n");
	ret1 = printf("String: %s\n", "42 School");
	ret2 = ft_printf("String: %s\n", "42 School");
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);
	
	printf("Test 4 - Percent:\n");
	ret1 = printf("100%%\n");
	ret2 = ft_printf("100%%\n");
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);
}

static void	test_numbers(void)
{
	int	ret1;
	int	ret2;

	printf("=== Number Tests ===\n");
	
	printf("Test 5 - Decimal:\n");
	ret1 = printf("%d, %d, %d\n", 0, -42, 2147483647);
	ret2 = ft_printf("%d, %d, %d\n", 0, -42, 2147483647);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);
	
	printf("Test 6 - Integer:\n");
	ret1 = printf("%i, %i, %i\n", 0, -42, INT_MIN);
	ret2 = ft_printf("%i, %i, %i\n", 0, -42, INT_MIN);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);
	
	printf("Test 7 - Unsigned:\n");
	ret1 = printf("%u, %u, %u\n", 0u, 42u, 4294967295u);
	ret2 = ft_printf("%u, %u, %u\n", 0u, 42u, 4294967295u);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);
}

static void	test_hex_pointer(void)
{
	int	ret1;
	int	ret2;
	int	x;

	x = 42;
	printf("=== Hex & Pointer Tests ===\n");
	
	printf("Test 8 - Hex lowercase:\n");
	ret1 = printf("%x, %x, %x\n", 0, 255, 48879);
	ret2 = ft_printf("%x, %x, %x\n", 0, 255, 48879);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);
	
	printf("Test 9 - Hex uppercase:\n");
	ret1 = printf("%X, %X, %X\n", 0, 255, 48879);
	ret2 = ft_printf("%X, %X, %X\n", 0, 255, 48879);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);
	
	printf("Test 10 - Pointer:\n");
	ret1 = printf("%p, %p\n", NULL, &x);
	ret2 = ft_printf("%p, %p\n", NULL, &x);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);
}

static void	test_edge_cases(void)
{
	int	ret1;
	int	ret2;

	printf("=== Edge Cases ===\n");
	
	printf("Test 11 - NULL string:\n");
	ret1 = printf("%s\n", (char *)NULL);
	ret2 = ft_printf("%s\n", (char *)NULL);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);
	
	printf("Test 12 - Mix:\n");
	ret1 = printf("char: %c, str: %s, int: %d, hex: %x\n", 'Z', "test", -42, 42);
	ret2 = ft_printf("char: %c, str: %s, int: %d, hex: %x\n", 'Z', "test", -42, 42);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);
}

int	main(void)
{
	printf("========================================\n");
	printf("       ft_printf Test Suite\n");
	printf("========================================\n\n");
	
	test_basic();
	test_numbers();
	test_hex_pointer();
	test_edge_cases();
	
	printf("========================================\n");
	printf("       Tests Completed\n");
	printf("========================================\n");
	return (0);
}