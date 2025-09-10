/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ai <ai@student.42>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by ai                #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by ai               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>

# define DECIMAL "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define NULL_STR "(null)"

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_string(const char *s);
int		ft_print_percent(void);
int		ft_print_signed(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, int uppercase);
int		ft_print_pointer(void *ptr);
int		ft_put_unbr_base(unsigned long long n, const char *base);
size_t	ft_strlen(const char *s);

#endif