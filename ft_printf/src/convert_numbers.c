/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_numbers.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/07 22:49:21 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_int_sign(t_flags flags, int sign)
{
	if (sign)
		return (putchar_count('-'));
	else if (flags.plus)
		return (putchar_count('+'));
	else if (flags.space)
		return (putchar_count(' '));
	return (0);
}

static int	calculate_int_content_width(t_flags flags, int str_len, int sign)
{
	int	precision;
	int	content_width;

	if (flags.precision_set && flags.precision > str_len)
		precision = flags.precision;
	else
		precision = str_len;
	if (flags.precision_set && flags.precision == 0 && str_len == 0)
		precision = 0;
	content_width = precision;
	if (flags.plus || flags.space || sign)
		content_width++;
	return (content_width);
}

static int	print_int_content(char *str, int str_len, t_flags flags, int sign)
{
	int	count;
	int	content_width;

	content_width = calculate_int_content_width(flags, str_len, sign);
	count = 0;
	if (!flags.minus)
	{
		if (flags.zero && !flags.precision_set)
		{
			count += print_int_sign(flags, sign);
			count += print_padding(flags.width - content_width, 1);
		}
		else
		{
			count += print_padding(flags.width - content_width, 0);
			count += print_int_sign(flags, sign);
		}
	}
	else
		count += print_int_sign(flags, sign);
	if (flags.precision_set && flags.precision > str_len)
		count += print_padding(flags.precision - str_len, 1);
	if (str_len > 0)
		count += putstr_count(str, -1);
	if (flags.minus)
		count += print_padding(flags.width - count, 0);
	return (count);
}

static char	*extract_int_str(int n, int *sign)
{
	char	*str;
	char	*temp;

	str = ft_itoa(n);
	if (!str)
		return (NULL);
	if (str[0] == '-')
		*sign = 1;
	else
		*sign = 0;
	if (*sign)
	{
		temp = str;
		str = ft_strdup(str + 1);
		free(temp);
	}
	return (str);
}

int	handle_int(va_list args, t_flags flags)
{
	int		n;
	char	*str;
	int		str_len;
	int		sign;

	n = va_arg(args, int);
	str = extract_int_str(n, &sign);
	if (!str)
		return (0);
	str_len = ft_strlen(str);
	if (flags.precision_set && flags.precision == 0 && n == 0)
		str_len = 0;
	n = print_int_content(str, str_len, flags, sign);
	free(str);
	return (n);
}

int	handle_unsigned(va_list args, t_flags flags)
{
	unsigned int	n;
	char			*str;
	int				count;
	int				str_len;
	int				precision;

	n = va_arg(args, unsigned int);
	str = ft_utoa_base(n, 10, 0);
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
		if (flags.zero && !flags.precision_set)
			count += print_padding(flags.width - precision, 1);
		else
			count += print_padding(flags.width - precision, 0);
	}
	if (flags.precision_set && flags.precision > str_len)
		count += print_padding(flags.precision - str_len, 1);
	if (str_len > 0)
		count += putstr_count(str, -1);
	if (flags.minus)
		count += print_padding(flags.width - count, 0);
	free(str);
	return (count);
}
