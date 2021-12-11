/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:35:37 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/12/11 17:03:40 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void	is_player(t_map_data *data)
{
	int	i;
	int	j;
	int	num_player;

	num_player = 0;
	j = 0;
	i = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
				num_player++;
			i++;
		}
		j++;
	}
	if (num_player != 1)
		error_message("Provide (only) one player");
}

void	is_exit(t_map_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'E')
				return ;
			i++;
		}
		j++;
	}
	error_message("No exit found. Please write a correct map");
}

void	check_map_len(t_map_data *data)
{
	size_t	i;
	int		j;

	j = 0;
	i = ft_strlen(data->map[0]);
	while (data->map[j])
	{
		if (i == ft_strlen(data->map[j]))
			printf("%s\n", data->map[j++]);
		else
			error_message("Map length not identical");
	}
}

void	check_one_map(t_map_data *data)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	k = ft_strlen(data->map[0]);
	printf("map data height is : %i\n", data->h);
	while (data->map[j][i])
	{
		if (data->map[j][i] == '1' && data->map[data->h - 1][i] == '1')
			i++;
		else
			error_message("Map is not surrounded by one's");
	}
	j = 1;
	while (j < data->h - 1)
	{
		if (data->map[j][0] == '1' && data->map[j][k - 1] == '1')
			j++;
		else
			error_message("Map not surrounded by one's");
	}
}

int	can_move(t_map_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return (0);
	else if (data->map[y][x] == 'C')
	{	
		printf("collectibles %i\n", data->collectibles);
		data->map[y][x] = '0';
		data->collectibles--;
	}
	else if (data->map[y][x] == 'E' && data->collectibles != 0)
	{
		return (0);
	}
	else if (data->map[y][x] == 'E' && data->collectibles == 0)
	{
		write(1, "Congrats! You finished the level!\n", 35);
		exit(0);
	}
	return (1);
}
