/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:33:26 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/05/13 11:36:42 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	i;
	char	*src;
	int		len;

	len = 0;
	i = 0;
	src = (char *)str;
	while (src[len] != '\0')
		len++;
	(dest = malloc(sizeof(char) * len + 1));
	if (!dest)
		return (NULL);
	while (i < ft_strlen(src))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
	free (dest);
}
