/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:14:43 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/28 21:42:06 by pamoutaf         ###   ########.fr       */
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

void	check_map_len(t_map_data *data)
{
	size_t	i;
	size_t	j;
	
	j = 0;
	i = ft_strlen(data->map[j]);
	
	while (data->map[j])
	{
		if (i == ft_strlen(data->map[j]))
		{
			j++;
			printf("debug\n");
		}
		//else
	//	error_message();
	}
}

void	error_message()
{
	write(1, "Error\n", 6);
	exit(0);
}

t_map_data *parse_map(const char *filename, t_map_data *data)
{
	int	i;
	int	fd;
	
	data->height = count_lines(filename);
	printf("%i\n", data->height);
	data->map = malloc(sizeof(char *) * data->height);
	if (!data->map)
		error_message();
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_message();
	i = 0;
	while (i < data->height)
		data->map[i++] = get_next_line(fd);
	data->len = ft_strlen(data->map[0]) - 1;
	end_of_file(data);
	//check_map_len(data);
	return (data);
}
