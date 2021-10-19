/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:09:46 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/05/20 16:41:27 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)big;
	s2 = (char *)little;
	if (s2[i] == '\0' || s2 == NULL)
		return (s1);
	if (ft_strlen(s2) > len)
		return (NULL);
	while (big[i] && ft_strlen(s2) <= len)
	{
		if (ft_strncmp(&s1[i], s2, ft_strlen(s2)) == 0 && s1[i] == *s2)
		{
			return (&s1[i]);
		}
		i++;
		len--;
	}
	return (NULL);
}
