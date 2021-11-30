/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:14:43 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/30 14:51:48 by pamoutaf         ###   ########.fr       */
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
	data->map[i] = NULL;
}

void	check_map_len(t_map_data *data)
{
	size_t	i;
	int	j;
	
	j = 0;
	i = ft_strlen(data->map[j]);
	while (data->map[j])
	{
		if (i == ft_strlen(data->map[j]) || (j == data->height - 1 && i == ft_strlen(data->map[0])))
		{
			printf(" data len : %i\n", data->len);
			printf("%s\n", data->map[j]);
			j++;
		}
		else
			error_message();
	}
}

void	check_one_map(t_map_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->map[j])
	{
		if (data->map[0][i] == '1' && data->map[data->height - 1][i] == '1')
		{
			i++;
			if (data->map[j][0] == '1' && data->map[j][data->len - 1] == '1')
				j++;
		}
		else
		{
			printf("check_one_map");
			error_message();
		}	
	}
}

void	error_message()
{
	write(2, "Error\n", 6);
	exit(0);
}

t_map_data *parse_map(const char *filename, t_map_data *data)
{
	int	i;
	int	fd;
	
	data->height = count_lines(filename);
	printf("%i\n", data->height);
	data->map = malloc(sizeof(char *) * (data->height + 1));
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
	check_map_len(data);
	check_one_map(data);
	return (data);
}
