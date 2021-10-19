/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:45:38 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/05/13 11:41:11 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*s;
	char	ch;

	ch = (char)c;
	i = ft_strlen(str);
	s = (char *)str;
	while (i > 0 && s[i] != ch)
		i--;
	if (s[i] == ch)
		return (&s[i]);
	else
		return (NULL);
}
