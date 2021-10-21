/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:56:03 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/10/19 13:41:06 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_double_percent(char c)
{
	write(1, "%", 1);
	return (1);
}

void	ft_putnbr_p(unsigned long n)
{
	if (n >= 16)
	{
		ft_putnbr_p(n / 16);
		ft_putnbr_p(n % 16);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else
		ft_putchar(n + 'W');
}

int	ft_conversion_p(va_list params)
{
	unsigned long	current;
	int				len;

	current = va_arg(params, unsigned long);
	ft_putstr("0x");
	ft_putnbr_p(current);
	len = ft_len_p(current) + 2;
	return (len);
}
