/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nssokols <nssokols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by nssokols          #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by nssokols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *format, ...);

int				ft_print_char(int c);
int				ft_print_str(const char *s);
int				ft_print_percent(void);

int				ft_print_signed(int n);
int				ft_print_unsigned(unsigned int n);
int				ft_print_hex_lower(unsigned int n);
int				ft_print_hex_upper(unsigned int n);
int				ft_print_pointer(void *p);

size_t			ft_strlen_safe(const char *s);
int				ft_write_str(const char *s, size_t len);

#endif

