/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:52:19 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/28 21:53:08 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	ft_nblen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		neg;
	long	nbr;
	char	*temp;

	neg = 0;
	nbr = n;
	if (nbr < 0)
	{
		neg = 1;
		nbr = nbr * -1;
	}
	i = ft_nblen(n);
	temp = (char *)malloc(sizeof(char) * i + 1);
	if (!(temp || n == 0))
		return (NULL);
	temp[i--] = '\0';
	while (i >= 0)
	{
		temp[i--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (neg == 1)
		temp[0] = '-';
	return (temp);
}
