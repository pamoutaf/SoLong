/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:20:31 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/09/13 15:33:29 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s1)
{
	size_t	i;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count;
	char	*new_str;
	size_t	size;

	if (s1 == NULL)
		s1 = malloc(sizeof(char));
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	count = -1;
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	new_str = (char *)malloc(sizeof(char) * size);
	if (new_str == NULL)
		return (NULL);
	while (s1[++count])
		new_str[count] = s1[count];
	count = -1;
	while (s2[++count])
		new_str[count + ft_strlen((char *)s1)] = s2[count];
	new_str[count + ft_strlen((char *)s1)] = '\0';
	free((char *)s1);
	return (new_str);
}

int	ft_strchr(const char *s, int c)
{
	char	*s1;
	char	car;
	int		i;

	i = 0;
	if (s == NULL)
		return (-1);
	car = (char) c;
	s1 = (char *) s;
	while (s1[i])
	{
		if (s1[i] == car)
			return (i);
		i++;
	}
	if (car == '\0' && s1[i] == '\0')
		return (i);
	return (-1);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	size;

	i = 0;
	if (ft_strlen((char *)s) < start)
	{
		substr = (malloc(sizeof(char)));
		if (!substr)
			return (NULL);
		return (substr);
	}
	size = len;
	if (ft_strlen(s) < len)
		size = ft_strlen(s);
	substr = malloc(sizeof(char) * size + 1);
	if (substr == NULL)
		return (NULL);
	while (s[start] && i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
