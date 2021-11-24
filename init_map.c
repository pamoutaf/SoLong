/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:14:43 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/23 17:51:45 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int	count_lines(const char *map)
{
	int			numlines;
	char		*buf;
	int			fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (-1);
	numlines = 0;
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		numlines++;
		free(buf);
		buf = get_next_line(fd);
	}
	return (numlines);
}

void end_of_file(t_map_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->len)
		{
			if (data->map[i][j] == '\n')
				data->map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

t_map_data *parse_map(const char *filename, t_map_data *data)
{
	int	i;
	int	fd;
	
	data->height = count_lines(filename);
	printf("%i\n", data->height);
	data->map = malloc(sizeof(char *) * data->height);
	if (!data->map)
	{
		printf("Error");
		exit(-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error");
		exit(-1);
	}
	i = 0;
	while (i < data->height)
		data->map[i++] = get_next_line(fd);
	data->len = ft_strlen(data->map[0]) - 1;
	end_of_file(data);
	printf("%s", data->map[0]);
	printf("%i\n", data->len);
	printf("%s", data->map[0]);
	return (data);
}
