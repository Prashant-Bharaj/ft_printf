/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/07 22:49:21 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_body_part(char *str, int str_len, t_flags flags,
		int count)
{
	if (flags.precision_set && flags.precision > str_len)
		count += print_padding(flags.precision - str_len, 1);
	if (str_len > 0)
		count += putstr_count(str, -1);
	if (flags.minus)
		count += print_padding(flags.width - count, 0);
	return (count);
}

int	handle_hex(va_list args, t_flags flags, int uppercase)
{
	unsigned int	n;
	char			*str;
	int				count;
	int				str_len;
	int				precision;

	n = va_arg(args, unsigned int);
	str = ft_utoa_base(n, 16, uppercase);
	if (!str)
		return (0);
	str_len = ft_strlen(str);
	if (flags.precision_set && flags.precision == 0 && n == 0)
		str_len = 0;
	if (flags.precision_set && flags.precision > str_len)
		precision = flags.precision;
	else
		precision = str_len;
	count = 0;
	if (!flags.minus)
	{
		if (flags.hash && n != 0)
		{
			if (flags.zero && !flags.precision_set)
				count += print_padding(flags.width - precision - 2, 1);
			else
				count += print_padding(flags.width - precision - 2, 0);
		}
		else
		{
			if (flags.zero && !flags.precision_set)
				count += print_padding(flags.width - precision, 1);
			else
				count += print_padding(flags.width - precision, 0);
		}
	}
	if (flags.hash && n != 0)
	{
		if (uppercase)
			count += putstr_count("0X", -1);
		else
			count += putstr_count("0x", -1);
	}
	count = print_hex_body_part(str, str_len, flags, count);
	free(str);
	return (count);
}

int	handle_pointer(va_list args, t_flags flags)
{
	unsigned long long	ptr;
	char				*str;
	int					count;
	int					str_len;
	int					precision;
	int					is_null;

	ptr = (unsigned long long)va_arg(args, void *);
	is_null = (ptr == 0);
	if (is_null)
	{
		str_len = 5;
		if (flags.precision_set && flags.precision == 0)
			str_len = 0;
		if (flags.precision_set && flags.precision > str_len)
			precision = flags.precision;
		else
			precision = str_len;
		count = 0;
		if (!flags.minus)
			count += print_padding(flags.width - precision, 0);
		if (str_len > 0)
			count += putstr_count("(nil)", -1);
		if (flags.minus)
			count += print_padding(flags.width - count, 0);
		return (count);
	}
	str = ft_utoa_base(ptr, 16, 0);
	if (!str)
		return (0);
	str_len = ft_strlen(str);
	if (flags.precision_set && flags.precision == 0 && ptr == 0)
		str_len = 0;
	if (flags.precision_set && flags.precision > str_len)
		precision = flags.precision;
	else
		precision = str_len;
	count = 0;
	if (!flags.minus)
	{
		if (flags.zero && !flags.precision_set)
		{
			count += putstr_count("0x", -1);
			count += print_padding(flags.width - precision - 2, 1);
		}
		else
			count += print_padding(flags.width - precision - 2, 0);
	}
	if (flags.minus || !flags.zero || flags.precision_set)
		count += putstr_count("0x", -1);
	if (flags.precision_set && flags.precision > str_len)
		count += print_padding(flags.precision - str_len, 1);
	if (str_len > 0)
		count += putstr_count(str, -1);
	if (flags.minus)
		count += print_padding(flags.width - count, 0);
	free(str);
	return (count);
}
