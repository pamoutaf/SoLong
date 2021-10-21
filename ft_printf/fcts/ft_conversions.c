/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:15:56 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/10/18 18:26:01 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_conversion_id(va_list params)
{
	int		len;
	int		current;

	current = va_arg(params, int);
	len = ft_nbrlen(current);
	ft_putnbr(current);
	return (len);
}

char	ft_conversion_s(va_list params)
{
	int		i;
	char	*current;
	int		len;

	current = va_arg(params, char *);
	i = 0;
	ft_putstr(current);
	len = ft_strlen(current);
	return (len);
}

char	ft_conversion_c(va_list params)
{
	char	current;

	current = va_arg(params, int);
	ft_putchar(current);
	return (1);
}

int	ft_conversion_u(va_list params)
{
	unsigned long	current;
	int				len;

	current = va_arg(params, unsigned long);
	ft_putnbr_u(current);
	len = ft_nbrlen_u(current);
	return (len);
}
