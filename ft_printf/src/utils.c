/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prasingh <prasingh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:17 by prasingh          #+#    #+#             */
/*   Updated: 2025/12/07 22:49:21 by prasingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr_count(char *str, int precision)
{
	int	len;
	int	i;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (precision >= 0 && precision < len)
		len = precision;
	i = 0;
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int	print_padding(int count, int zero_flag)
{
	int		i;
	char	c;

	if (count <= 0)
		return (0);
	if (zero_flag)
		c = '0';
	else
		c = ' ';
	i = 0;
	while (i < count)
	{
		write(1, &c, 1);
		i++;
	}
	return (count);
}

static int	calculate_base_len(unsigned long long n, int base)
{
	int					len;
	unsigned long long	temp;

	len = 1;
	temp = n;
	while (temp >= (unsigned long long)base)
	{
		temp /= base;
		len++;
	}
	return (len);
}

char	*ft_utoa_base(unsigned long long n, int base, int uppercase)
{
	char	*str;
	char	*digits;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = calculate_base_len(n, base);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	else
	{
		len--;
		while (n > 0)
		{
			str[len--] = digits[n % base];
			n /= base;
		}
	}
	return (str);
}
