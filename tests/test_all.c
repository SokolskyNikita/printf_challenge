/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ai <ai@student.42>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by ai                #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by ai               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

struct s_capture
{
	int			old_fd;
	int			pipefd[2];
	char		*buf;
	size_t		len;
};

void		capture_start(struct s_capture *cap);
char		*capture_stop(struct s_capture *cap);
int			assert_eq_str(const char *got, const char *exp, const char *label);

static int	test_basic_text(void)
{
	struct s_capture	cap;
	char				*got;
{
	capture_start(&cap);
	ft_printf("Hello, world!\n");
	got = capture_stop(&cap);
	return (assert_eq_str(got, "Hello, world!\n", "plain text"));
}
}

static int	test_char_string_percent(void)
{
	struct s_capture	cap;
	char				*got;

	capture_start(&cap);
	ft_printf("%c %s %%", 'A', "str");
	got = capture_stop(&cap);
	return (assert_eq_str(got, "A str %", "%c %s %%"));
}

static int	test_signed_numbers(void)
{
	struct s_capture	cap;
	char				*got;
	int					err;

	err = 0;
	capture_start(&cap);
	ft_printf("%d %i %d", 0, -1, INT_MIN);
	got = capture_stop(&cap);
	err += assert_eq_str(got, "0 -1 -2147483648", "%d %i INT_MIN");
	return (err);
}

static int	test_unsigned_numbers(void)
{
	struct s_capture	cap;
	char				*got;

	capture_start(&cap);
	ft_printf("%u", 4294967295u);
	got = capture_stop(&cap);
	return (assert_eq_str(got, "4294967295", "%u UINT_MAX"));
}

static int	test_hex(void)
{
	struct s_capture	cap;
	char				*got;
	int					err;

	err = 0;
	capture_start(&cap);
	ft_printf("%x %X", 48879u, 48879u);
	got = capture_stop(&cap);
	err += assert_eq_str(got, "beef BEEF", "%x %X");
	return (err);
}

static int	test_pointer(void)
{
	struct s_capture	cap;
	char				*got;
	int					x;
	int					err;

	err = 0;
	x = 42;
	capture_start(&cap);
	ft_printf("%p", NULL);
	got = capture_stop(&cap);
	err += assert_eq_str(got, "(nil)", "%p NULL");

	capture_start(&cap);
	ft_printf("%p", &x);
	got = capture_stop(&cap);
	if (!got || strncmp(got, "0x", 2) != 0)
		err += assert_eq_str(got, "0x...", "%p non-null prefix");
	return (err);
}

static int	test_null_string(void)
{
	struct s_capture	cap;
	char				*got;

	capture_start(&cap);
	ft_printf("%s", (const char *)NULL);
	got = capture_stop(&cap);
	return (assert_eq_str(got, "(null)", "%s NULL"));
}

static int	test_trailing_percent(void)
{
	struct s_capture	cap;
	char				*got;

	capture_start(&cap);
	ft_printf("end %");
	got = capture_stop(&cap);
	return (assert_eq_str(got, "end ", "trailing %"));
}

static int	test_invalid_base_guard(void)
{
	int		written;

	written = ft_put_unbr_base(10, "0");
	if (written != 0)
		return (assert_eq_str("notzero", "zero", "invalid base returns 0"));
	written = ft_put_unbr_base(10, NULL);
	if (written != 0)
		return (assert_eq_str("notzero", "zero", "NULL base returns 0"));
	return (0);
}

static int	test_null_format(void)
{
	int		written;

	written = ft_printf(NULL);
	if (written != -1)
		return (assert_eq_str("not-1", "-1", "NULL format returns -1"));
	return (0);
}

static int	test_unknown_specifier(void)
{
	struct s_capture	cap;
	char				*got;

	capture_start(&cap);
	ft_printf("%q");
	got = capture_stop(&cap);
	return (assert_eq_str(got, "", "unknown specifier %q prints nothing"));
}

static int	test_strlen_null(void)
{
	struct s_capture	cap;
	char				*got;

	capture_start(&cap);
	ft_printf("%d", (int)ft_strlen(NULL));
	got = capture_stop(&cap);
	return (assert_eq_str(got, "0", "ft_strlen(NULL) == 0"));
}

static int	test_invalid_bases_plus_and_dup(void)
{
	struct s_capture	cap;
	char				*got;
	int					err;

	err = 0;
	capture_start(&cap);
	(void)ft_put_unbr_base(10, "+0123456789");
	got = capture_stop(&cap);
	err += assert_eq_str(got, "", "invalid base with plus prints nothing");

	capture_start(&cap);
	(void)ft_put_unbr_base(10, "00123456789");
	got = capture_stop(&cap);
	err += assert_eq_str(got, "", "invalid base with duplicate prints nothing");
	return (err);
}

int			main(void)
{
	int	err;

	err = 0;
	err += test_basic_text();
	err += test_char_string_percent();
	err += test_signed_numbers();
	err += test_unsigned_numbers();
	err += test_hex();
	err += test_pointer();
	err += test_null_string();
	err += test_trailing_percent();
	err += test_invalid_base_guard();
	err += test_null_format();
	err += test_unknown_specifier();
	err += test_strlen_null();
	err += test_invalid_bases_plus_and_dup();
	if (err != 0)
		return (1);
	return (0);
}

