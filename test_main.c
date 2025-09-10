/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:00:00 by student          #+#    #+#             */
/*   Updated: 2025/01/10 10:00:00 by student         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

static void	test_characters(void)
{
	printf("\n=== Testing Character Format ===\n");
	ft_printf("ft_printf: %c\n", 'A');
	printf("   printf: %c\n", 'A');
	ft_printf("ft_printf: %c\n", '0');
	printf("   printf: %c\n", '0');
	ft_printf("ft_printf: %c\n", '\n');
	printf("   printf: %c\n", '\n');
}

static void	test_strings(void)
{
	printf("\n=== Testing String Format ===\n");
	ft_printf("ft_printf: %s\n", "Hello World");
	printf("   printf: %s\n", "Hello World");
	ft_printf("ft_printf: %s\n", "");
	printf("   printf: %s\n", "");
	ft_printf("ft_printf: %s\n", (char *)NULL);
	printf("   printf: (null)\n");
}

static void	test_pointers(void)
{
	int		x;
	void	*ptr;

	x = 42;
	ptr = &x;
	printf("\n=== Testing Pointer Format ===\n");
	ft_printf("ft_printf: %p\n", ptr);
	printf("   printf: %p\n", ptr);
	ft_printf("ft_printf: %p\n", NULL);
	printf("   printf: %p\n", NULL);
	ft_printf("ft_printf: %p\n", (void *)0xdeadbeef);
	printf("   printf: %p\n", (void *)0xdeadbeef);
}

static void	test_integers(void)
{
	printf("\n=== Testing Integer Formats ===\n");
	ft_printf("ft_printf: %d\n", 42);
	printf("   printf: %d\n", 42);
	ft_printf("ft_printf: %d\n", -42);
	printf("   printf: %d\n", -42);
	ft_printf("ft_printf: %d\n", 0);
	printf("   printf: %d\n", 0);
	ft_printf("ft_printf: %i\n", INT_MAX);
	printf("   printf: %i\n", INT_MAX);
	ft_printf("ft_printf: %i\n", INT_MIN);
	printf("   printf: %i\n", INT_MIN);
}

static void	test_unsigned(void)
{
	printf("\n=== Testing Unsigned Format ===\n");
	ft_printf("ft_printf: %u\n", 42);
	printf("   printf: %u\n", 42);
	ft_printf("ft_printf: %u\n", 0);
	printf("   printf: %u\n", 0);
	ft_printf("ft_printf: %u\n", UINT_MAX);
	printf("   printf: %u\n", UINT_MAX);
}

static void	test_hex_lower(void)
{
	printf("\n=== Testing Lowercase Hex Format ===\n");
	ft_printf("ft_printf: %x\n", 255);
	printf("   printf: %x\n", 255);
	ft_printf("ft_printf: %x\n", 0);
	printf("   printf: %x\n", 0);
	ft_printf("ft_printf: %x\n", 0xdeadbeef);
	printf("   printf: %x\n", 0xdeadbeef);
	ft_printf("ft_printf: %x\n", UINT_MAX);
	printf("   printf: %x\n", UINT_MAX);
}

static void	test_hex_upper(void)
{
	printf("\n=== Testing Uppercase Hex Format ===\n");
	ft_printf("ft_printf: %X\n", 255);
	printf("   printf: %X\n", 255);
	ft_printf("ft_printf: %X\n", 0);
	printf("   printf: %X\n", 0);
	ft_printf("ft_printf: %X\n", 0xDEADBEEF);
	printf("   printf: %X\n", 0xDEADBEEF);
	ft_printf("ft_printf: %X\n", UINT_MAX);
	printf("   printf: %X\n", UINT_MAX);
}

static void	test_percent(void)
{
	printf("\n=== Testing Percent Format ===\n");
	ft_printf("ft_printf: %%\n");
	printf("   printf: %%\n");
	ft_printf("ft_printf: 100%%\n");
	printf("   printf: 100%%\n");
}

static void	test_mixed(void)
{
	printf("\n=== Testing Mixed Formats ===\n");
	ft_printf("ft_printf: %s %d %x\n", "Number:", 42, 42);
	printf("   printf: %s %d %x\n", "Number:", 42, 42);
	ft_printf("ft_printf: %c%c%c\n", 'A', 'B', 'C');
	printf("   printf: %c%c%c\n", 'A', 'B', 'C');
	ft_printf("ft_printf: %p %p %p\n", NULL, (void *)1, (void *)0xFFFF);
	printf("   printf: %p %p %p\n", NULL, (void *)1, (void *)0xFFFF);
}

static void	test_edge_cases(void)
{
	int	ret1;
	int	ret2;

	printf("\n=== Testing Edge Cases ===\n");
	ret1 = ft_printf("ft_printf: Plain text only\n");
	ret2 = printf("   printf: Plain text only\n");
	printf("Return values: ft_printf=%d, printf=%d\n", ret1, ret2);
	ret1 = ft_printf("");
	ret2 = 0;
	printf("Empty string returns: ft_printf=%d, printf=%d\n", ret1, ret2);
	ret1 = ft_printf("End with percent: %");
	printf("\n");
	ret2 = 18;
	printf("\nEnd percent returns: ft_printf=%d, printf=%d\n", ret1, ret2);
}

static void	test_null_format(void)
{
	int	ret;
	int	saved_stdout;
	int	null_fd;

	printf("\n=== Testing NULL Format ===\n");
	saved_stdout = dup(1);
	null_fd = open("/dev/null", O_WRONLY);
	dup2(null_fd, 1);
	ret = ft_printf(NULL);
	dup2(saved_stdout, 1);
	close(null_fd);
	close(saved_stdout);
	printf("ft_printf(NULL) returns: %d\n", ret);
}

static void	test_coverage_completeness(void)
{
	printf("\n=== Testing Coverage Completeness ===\n");
	ft_printf("Multiple percents: %%%% and %%%%%%\n");
	ft_printf("Invalid format (ignored): %q\n");
	ft_printf("Numbers: %d %i %u\n", -1, -2, 3);
	ft_printf("Hex variations: %x %X\n", 15, 15);
	ft_printf("Large pointer: %p\n", (void *)0xFFFFFFFFFFFFFFFF);
	ft_printf("Zero pointer special: %p\n", (void *)0);
	ft_printf("Recursive numbers: %d %u\n", 1234567890, 1234567890);
}

int	main(void)
{
	printf("===== FT_PRINTF TEST SUITE =====\n");
	printf("Testing all format specifiers and edge cases\n");
	test_characters();
	test_strings();
	test_pointers();
	test_integers();
	test_unsigned();
	test_hex_lower();
	test_hex_upper();
	test_percent();
	test_mixed();
	test_edge_cases();
	test_null_format();
	test_coverage_completeness();
	printf("\n===== ALL TESTS COMPLETED =====\n");
	return (0);
}