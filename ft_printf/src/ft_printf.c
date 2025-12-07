/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/07 22:49:21 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


static int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * @brief Initializes the flags struct to default values.
 */
static t_flags	init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	// ... initialize other flags
	return (flags);
}

static int	handle_format(char specifier, va_list args, t_flags flags)
{
	// The 'flags' struct now contains all formatting rules.
	// This function is now much simpler.
	(void)flags; // Suppress unused variable warning for now.

	if (specifier == '%')
		return (print_char('%'));
	if (specifier == 'c')
	{
		// TODO: Implement width and '-' flag for char.
		return (print_char(va_arg(args, int)));
	}
	if (specifier == 's')
	{
		// TODO: Implement width, precision, and '-' for string.
		// char *str = va_arg(args, char *);
		// return (print_string(str, flags));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	total_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			t_flags flags = init_flags();
			i++;
			// --- PARSING STAGE ---
			// This loop parses flags like '-', '0', etc.
			while (format[i] == '-' || format[i] == '0')
			{
				if (format[i] == '-')
					flags.minus = 1;
				if (format[i] == '0')
					flags.zero = 1;
				i++;
			}
			// TODO: Add parsing for width, precision, '#', '+', ' ' here.

			// --- DISPATCH STAGE ---
			// After parsing, call the handler with the populated flags struct.
			total_len += handle_format(format[i], args, flags);
		}
		else
		{
			total_len += print_char(format[i]);
		}
		i++;
	}
	va_end(args);
	return (total_len);
}