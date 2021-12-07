/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:14:43 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/12/07 16:01:21 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int	count_lines(const char *map)
{
	size_t		numlines;
	char		*buf;
	int			fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_message("The map you have entered does not exist");
	numlines = 0;
	buf = get_next_line(fd);
	if (!buf)
		error_message("File probably empty");
	while (buf != NULL)
	{
		numlines++;
		free(buf);
		buf = get_next_line(fd);
	}
	return (numlines);
}

void	end_of_file(t_map_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->h)
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == '\n')
				data->map[j][i] = '\0';
			i++;
		}
		j++;
	}
	data->map[j] = NULL;
}

void	error_message(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	write(2, "Error\n", 7);
	while (str[i])
	{
		ft_putchar_fd(str[i], 2);
		i++;
	}
	write(2, "\n", 1);
	exit(0);
}

t_map_data	*parse_map(const char *filename, t_map_data *data)
{
	int	i;
	int	fd;

	check_map_name(filename);
	data->h = count_lines(filename);
	data->map = malloc(sizeof(char *) * (data->h + 1));
	if (!data->map)
		error_message("Map Allocation Failed");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_message("File Descriptor not found");
	i = 0;
	while (i < data->h)
		data->map[i++] = get_next_line(fd);
	end_of_file(data);
	data->len = ft_strlen(data->map[0]);
	check_map_len(data);
	check_one_map(data);
	is_player(data);
	is_exit(data);
	check_map_character(data);
	return (data);
}
