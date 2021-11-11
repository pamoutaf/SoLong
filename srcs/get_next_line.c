/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:20:48 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/10 18:08:53 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *buf, char *line)
{
	if (buf)
		free(buf);
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (NULL);
}

char	*ft_cut_line(char **line, char *buf)
{
	char	*str;
	char	*tmp;

	if (ft_strchr(*line, '\n') > -1)
	{
		str = ft_substr(*line, 0, ft_strchr(*line, '\n') + 1);
		if (!str)
			return (ft_free(buf, *line));
		tmp = *line;
		*line = ft_substr(tmp, ft_strchr(tmp, '\n') + 1,
				ft_strlen(tmp) - ft_strchr(tmp, '\n') + 1);
		free(tmp);
		if (!(*line))
		{
			free(str);
			return (ft_free(buf, *line));
		}
	}
	else
	{
		str = *line;
		*line = NULL;
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*line;
	int			ret;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(buf, line));
	ret = 1;
	while (ret > 0 && ft_strchr(line, '\n') == -1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (ft_free(buf, line));
		buf[ret] = '\0';
		if (ret)
			line = ft_strjoin(line, buf);
		if (!line)
			return (ft_free(buf, line));
	}
	if (line == NULL || line[0] == '\0')
		return (ft_free(buf, line));
	return (ft_cut_line(&line, buf));
}
