/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_chars.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/07 22:49:21 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(va_list args, t_flags flags)
{
	char	c;
	int		count;

	c = va_arg(args, int);
	count = 0;
	if (flags.minus)
	{
		count += putchar_count(c);
		count += print_padding(flags.width - 1, 0);
	}
	else
	{
		count += print_padding(flags.width - 1, 0);
		count += putchar_count(c);
	}
	return (count);
}

static int	get_string_precision(char *str, t_flags flags)
{
	int	str_len;
	int	precision;

	if (flags.precision_set)
		precision = flags.precision;
	else
		precision = -1;
	str_len = ft_strlen(str);
	if (precision >= 0 && precision < str_len)
		str_len = precision;
	return (str_len);
}

int	handle_string(va_list args, t_flags flags)
{
	char	*str;
	int		str_len;
	int		count;
	int		precision;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	if (flags.precision_set)
		precision = flags.precision;
	else
		precision = -1;
	str_len = get_string_precision(str, flags);
	count = 0;
	if (flags.minus)
	{
		count += putstr_count(str, precision);
		count += print_padding(flags.width - str_len, 0);
	}
	else
	{
		count += print_padding(flags.width - str_len, 0);
		count += putstr_count(str, precision);
	}
	return (count);
}

int	handle_percent(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		count += putchar_count('%');
		count += print_padding(flags.width - 1, 0);
	}
	else
	{
		if (flags.zero)
			count += print_padding(flags.width - 1, 1);
		else
			count += print_padding(flags.width - 1, 0);
		count += putchar_count('%');
	}
	return (count);
}
