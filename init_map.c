/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:14:43 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/16 10:42:46 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void	open_window(t_map_data *data)
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, data->len * 64, data->height * 64, "test");

	mlx_pixel_put(mlx, win, (data->len* 64)/2, (data->height * 64)/2, 0xFFFFFF);
}

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
	printf("%i\n", data->len);
	printf("%s", data->map[0]);
}
