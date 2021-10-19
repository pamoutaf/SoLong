/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:26:07 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/05/13 12:19:59 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str1 < str2)
		ft_memcpy(str1, str2, n);
	else
		while (n--)
			*(unsigned char *)(str1 + n) = *(unsigned char *)(str2 + n);
	return (str1);
}
