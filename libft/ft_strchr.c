/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:23:40 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/04/19 12:42:09 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;
	char	ch;

	ch = (char)c;
	i = 0;
	s = (char *)str;
	while (s[i] != '\0' && s[i] != ch)
		i++;
	if (s[i] == ch)
		return (&s[i]);
	else
		return (NULL);
}
