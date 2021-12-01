/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:07:54 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/30 15:23:06 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int key_hook(int keycode, void *param)
{
	t_global	*global;
	
	global = (t_global*)param;
	if (keycode == 13)
		move_back(global, global->map_data);
	if (keycode == 1)
		move_front(global, global->map_data);
	if (keycode == 0)
		move_left(global, global->map_data);
	if (keycode == 2)
		move_right(global, global->map_data);
	if (keycode == 53)
		exit(0);
	return (0);
}

int	can_move(t_map_data *data, int x, int y)
{
	if (data->map[y][x] == '1') //check that y and x is between 0 and data len & data height
		return (0);
	if (data->map[y][x] == 'E')
	{
		write(1, "Congrats! You finished the level!", 33);
		exit(0);
	}
	return (1);
}

void move_right(t_global *global, t_map_data *data)
{
	int		x;
	int		y;
	char	*add;
	
	x = global->pos.x;
	y = global->pos.y;
	if (can_move(data, x + 1, y))
	{
		if(global->map_data->map[y][x] == 'E')
			mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player_front, global->pos.x * 64, global->pos.y * 64);
		add = ft_itoa(global->map_data->steps);
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_wall, 0, 0);
		mlx_string_put(global->mlx, global->win, 10, 10, 0xFFFFFF, add);
		free(add);
		global->map_data->steps++;
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_empty, global->pos.x * 64, global->pos.y * 64);
		global->pos.x = global->pos.x + 1;
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player_right, global->pos.x * 64, global->pos.y * 64);
	}
}

void move_left(t_global *global, t_map_data *data)
{
	int		x;
	int		y;
	char	*add;
	
	x = global->pos.x;
	y = global->pos.y;
	
	if (can_move(data, x - 1, y))
	{
		if(global->map_data->map[y][x] == 'E')
			mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player_front, global->pos.x * 64, global->pos.y * 64);
		add = ft_itoa(global->map_data->steps);
		printf("first step : %i\n", global->map_data->steps);
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_wall, 0, 0);
		mlx_string_put(global->mlx, global->win, 10, 10, 0xFFFFFF, add);
		free(add);
		global->map_data->steps++;
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_empty, global->pos.x * 64, global->pos.y * 64);
		global->pos.x = global->pos.x - 1;
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player_left, global->pos.x * 64, global->pos.y * 64);
		printf("total steps so far : %i\n", global->map_data->steps);
	}
}

void move_front(t_global *global, t_map_data *data)
{
	int		x;
	int		y;
	char	*add;
	
	x = global->pos.x;
	y = global->pos.y;
	if (can_move(data, x, y + 1))
	{
		if(global->map_data->map[y][x] == 'E')
			mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player_front, global->pos.x * 64, global->pos.y * 64);
		add = ft_itoa(global->map_data->steps);
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_wall, 0, 0);
		mlx_string_put(global->mlx, global->win, 10, 10, 0xFFFFFF, add);
		printf("first step : %i\n", global->map_data->steps);
		free(add);
		global->map_data->steps++;
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_empty, global->pos.x * 64, global->pos.y * 64);
		global->pos.y = global->pos.y + 1;
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player_front, global->pos.x * 64, global->pos.y * 64);
		printf("total steps so far : %i\n", global->map_data->steps);
	}
}

void move_back(t_global *global, t_map_data *data)
{
	int		x;
	int		y;
	char	*add;
	
	x = global->pos.x;
	y = global->pos.y;
	if (can_move(data, x, y - 1 ))
	{
		if(global->map_data->map[y][x] == 'E')
			mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player_front, global->pos.x * 64, global->pos.y * 64);
		add = ft_itoa(global->map_data->steps);
		printf("first step : %i\n", global->map_data->steps);
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_wall, 0, 0);
		mlx_string_put(global->mlx, global->win, 10, 10, 0xFFFFFF, add);
		free(add);
		global->map_data->steps++;
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_empty, global->pos.x * 64, global->pos.y * 64);
		global->pos.y = global->pos.y - 1;
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player_back, global->pos.x * 64, global->pos.y * 64);
		printf("total steps so far : %i\n", global->map_data->steps);
	}
}