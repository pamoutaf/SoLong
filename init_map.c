/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:14:43 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/12/02 18:55:22 by pamoutaf         ###   ########.fr       */
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
		error_message();
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

void end_of_file(t_map_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->height)
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

void	check_map_len(t_map_data *data)
{
	size_t	i;
	int	j;
	
	j = 0;
	i = ft_strlen(data->map[j]);
	
	printf("i : %zu\n", i);
	while (data->map[j])
	{
		printf("debug here\n");
		if (i == ft_strlen(data->map[j]) || (j == data->height - 1 && i == ft_strlen(data->map[0]) - 1))
		{
			printf(" data len : %i\n", data->len);
			printf("%s\n", data->map[j]);
			j++;
		}
		else
			error_message("Map length not identical");
	}
}

void	check_one_map(t_map_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->map[j] || data->map[0][i])
	{
		printf(" i %d map %c\n", i, data->map[0][i]);
		if (data->map[0][i] == '1' && data->map[data->height - 1][i] == '1')
		{
			i++;
			printf("iteration i : %i\n", i);
			printf("data len : %i\n", data->len);
			if (data->map[j][0] == '1' && data->map[j][data->len] == '1')
			{
				j++;
				printf("iteration j : %i\n", j);
			}
		}
		else
			error_message("Map is not surrounded by 1's");
	}
}

void	error_message(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	exit(0);
}

t_map_data *parse_map(const char *filename, t_map_data *data)
{
	int	i;
	int	fd;
	
	data->height = count_lines(filename);
	printf("map height %i\n", data->height);
	data->map = malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
		error_message("Map Allocation Failed");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_message("File Descriptor Failed");
	i = 0;
	while (i < data->height)
		data->map[i++] = get_next_line(fd);
	data->len = ft_strlen(data->map[0]) - 1;
	i = 0;
	while (i < data->height)
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	end_of_file(data);
	check_map_len(data);
	check_one_map(data);
	return (data);
}
