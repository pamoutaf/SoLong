/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:35:37 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/12/05 10:12:05 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void	is_player(t_map_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->map[j] || data->map[0][i])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
				return;
			i++;
		}
		j++; 
	}
	error_message("No player found. Please write a correct map");
}

void	is_exit(t_map_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->map[j] || data->map[0][i])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'E')
				return;
			i++;
		}
		j++; 
	}
	error_message("No exit found. Please write a correct map");
}

void	check_map_len(t_map_data *data)
{
	size_t	i;
	int	j;
	
	j = 0;
	i = ft_strlen(data->map[j]);
	while (data->map[j])
	{
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
	int k;

	j = 0;
	i = 0;
	k = ft_strlen(data->map[0]);
	printf("map data height is : %i\n", data->height);
	while (data->map[j][i])
	{
		if (data->map[j][i] == '1' && data->map[data->height - 1][i] == '1')
			i++;
		else
			error_message("Map is not surrounded by one's\n");
	}
	j = 1;
	while (j < data->height - 1)
	{
		printf("data->len here : %i\n", k);
		if (data->map[j][0] == '1' && data->map[j][k - 1] == '1')
			j++;
		else
			error_message("Map not surrounded by one's\n");
	}
}

/*
void	check_one_map(t_map_data *data)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (data->map[j] || data->map[0][i])
	{
		printf(" i %d map %c\n", i, data->map[0][i]);
		if (data->map[0][i] == '1' && data->map[data->height - 1][i] == '1')
		{
			i++;
			// printf("iteration i : %i\n", i);
			// printf("data len : %i\n", data->len);
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
*/
int	can_move(t_map_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'E')
	{
		write(1, "Congrats! You finished the level!", 33);
		exit(0);
	}
	return (1);
}
