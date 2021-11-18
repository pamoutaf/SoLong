/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:14:43 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/18 17:43:26 by pamoutaf         ###   ########.fr       */
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

void parse_map(const char *filename, t_map_data *data)
{
	int		i;
	int		fd;
	
	data->height = count_lines(filename);
	printf("%i\n", data->height);
	data->map = malloc(sizeof(char *) * data->height + 1);
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
	data->map[i] = NULL;
	data->len = ft_strlen(data->map[0]) - 1;
	printf("len : %i\n", data->len);
	i = 0;
	while (data->map[i])
		printf("%s", data->map[i++]);
	close (fd);
}
// check get next line