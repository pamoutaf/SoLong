/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:03:00 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/05/13 11:37:42 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	t;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] && (j + i + 1) < destsize)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (!src[j])
		dest[i + j] = '\0';
	t = j;
	j = ft_strlen(src);
	if (destsize == 0)
		return (j);
	if (i < destsize)
	{
		dest[t + i] = '\0';
		return (i + j);
	}
	else
		return (destsize + j);
}
