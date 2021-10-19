/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:52:55 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/05/13 11:43:51 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
