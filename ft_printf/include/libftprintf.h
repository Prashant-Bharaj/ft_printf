/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:47:18 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/07 22:49:20 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

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
	// ... add other flags here as you implement them (width, precision, etc.)
}	t_flags;

int		ft_printf(const char *format, ...);

#endif
