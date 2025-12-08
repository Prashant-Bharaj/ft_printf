/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:47:18 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/08 15:19:26 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

/**
 * @brief A struct to hold all parsed formatting flags for a specifier.
 *
 * @param minus      Left-justify the output ('-').
 * @param zero       Pad with zeros instead of spaces ('0').
 * @param width      Minimum field width.
 * @param precision  Precision for numbers or max length for strings ('.').
 * @param hash       Alternate form for hex/octal ('#').
 * @param space      Print a space before a positive number (' ').
 * @param plus       Print a '+' before a positive number ('+').
 */
typedef struct s_flags
{
	int	minus;
	int	zero;
	int	hash;
	int	plus;
	int	space;
	int	width;
	int	precision;
	int	precision_set;
}	t_flags;

int		ft_printf(const char *format, ...);

t_flags	init_flags(void);
void	parse_flags(const char *format, int *i, t_flags *flags, va_list args);

int		handle_char(va_list args, t_flags flags);
int		handle_string(va_list args, t_flags flags);
int		handle_percent(t_flags flags);
int		handle_int(va_list args, t_flags flags);
int		handle_unsigned(va_list args, t_flags flags);
int		handle_hex(va_list args, t_flags flags, int uppercase);
int		handle_pointer(va_list args, t_flags flags);

int		putchar_count(char c);
int		putstr_count(char *str, int precision);
int		print_padding(int count, int zero_flag);
char	*ft_utoa_base(unsigned long long n, int base, int uppercase);

#endif
