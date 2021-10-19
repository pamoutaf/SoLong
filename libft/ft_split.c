/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:28:37 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/05/17 12:24:50 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freespace(int i, char **dest)
{
	while (i)
		free(dest[i--]);
	free (dest);
}

static int	ft_charset(char const *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			w++;
		while (s[i] != c && s[i + 1] != '\0')
			i++;
		i++;
	}
	return (w);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		cnt;
	int		i;

	cnt = ft_word_count(s, c);
	dest = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < cnt)
	{
		while (s && *s && *s == c)
			s++;
		dest[i] = ft_substr(s, 0, ft_charset(s, c));
		if (!dest)
		{
			ft_freespace(i, dest);
			return (NULL);
		}
		s += ft_charset(s, c);
		i++;
	}
	dest[i] = 0;
	return (dest);
}
