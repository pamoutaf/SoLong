/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:07:54 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/28 14:48:42 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int key_hook(int keycode, void *param)
{
	t_global	*global;
	
	global = (t_global*)param;
	printf("keycode : %d\n", keycode);
	//printf("key_hook pointer : %p\n", global->win);
	if (keycode == 13)
		move_vertical(global, global->map_data, -1);
	if (keycode == 1)
		move_vertical(global, global->map_data, 1);
	if (keycode == 0)
		move_horizontal(global, global->map_data, -1);
	if (keycode == 2)
		move_horizontal(global, global->map_data, 1);
	if (keycode == 53)
		exit(0);
	return (0);
}

int	can_move(t_map_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return (0);
	printf("map data checkwall: %p\n", data);
	return (1);
}

void move_vertical(t_global *global, t_map_data *data, int direction)
{
	int		x;
	int		y;
	
	x = global->pos.x;
	y = global->pos.y;
	printf("position Y : %i\n", global->pos.y);
	printf("position X : %i\n", global->pos.x);
	if (can_move(data, x, y + direction))
	{
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_empty, global->pos.x * 64, global->pos.y * 64);
		global->pos.y = global->pos.y +(direction);

		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player, global->pos.x * 64, global->pos.y * 64);
		printf("new position x: %i\n", global->pos.y);
		printf("----------------------------------\n");
	}
}

void move_horizontal(t_global *global, t_map_data *data, int direction)
{
	int		x;
	int		y;
	
	x = global->pos.x;
	y = global->pos.y;
	printf("position Y : %i\n", global->pos.y);
	printf("position X : %i\n", global->pos.x);
	if (can_move(data, x + direction, y))
	{
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_empty, global->pos.x * 64, global->pos.y * 64);
		global->pos.x = global->pos.x +(direction);
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player, global->pos.x * 64, global->pos.y * 64);
		printf("new position x: %i\n", global->pos.x);
		printf("----------------------------------\n");
	}
}