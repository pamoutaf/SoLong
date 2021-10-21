/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:03:28 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/10/19 13:12:07 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	if (s == NULL)
		write(1, "(null)", 6);
	write(1, s, ft_strlen(s));
}

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n == -2147483648)
	{
		ft_putchar('2');
		n = (n % 1000000000);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_putnbr_u(unsigned int n)
{
	if (n > 9 && n < 4294967295)
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	else if (n >= 4294967295)
		write(1, "4294967295", 10);
	else if (n < 0)
		write(1, "0", 1);
	else
		ft_putchar(n + '0');
}
