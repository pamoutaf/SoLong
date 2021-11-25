/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:07:54 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/25 18:01:45 by pamoutaf         ###   ########.fr       */
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

int	check_wall(t_map_data *data, int x, int y)
{
	if (data->map[y][x] == 1)
		return (0);
	printf("map data checkwall: %p\n", data);
	return (1);
}

void move_vertical(t_global *global, t_map_data *data, int direction)
{
	int		x;
	int		y;
	t_pos	pos;

	pos = png_to_win(global->mlx, global->map_data, global->win, global->img);
	x = pos.x;
	y = pos.y;
	printf("position Y : %i\n", pos.y);
	printf("position X : %i\n", pos.x);
	if (check_wall(data, x, y + direction))
	{
		//mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_empty, pos.x, pos.y);
		pos.y = pos.y +(direction);
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player, pos.x * 64, pos.y * 64);
		//mlx_destroy_image(global->mlx, global->img->sprite_player);
		printf("new position y: %i\n", pos.y);
	}
}

t_pos move_horizontal(t_global *global, t_map_data *data, int direction)
{
	int		x;
	int		y;
	t_pos	pos;
	void	*mlx_destroy;
	void	*img_destroy;

	pos = png_to_win(global->mlx, global->map_data, global->win, global->img);
	x = pos.x;
	y = pos.y;
	//mlx_destroy = global->mlx;
	//img_destroy = global->img->sprite_player;
	printf("position Y : %i\n", pos.y);
	printf("position X : %i\n", pos.x);
	if (check_wall(data, x + direction, y))
	{
		//mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_empty, pos.x, pos.y);
		pos.x = pos.x +(direction);
		//mlx_destroy_image(mlx_destroy, img_destroy);
		mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player, pos.x * 64, pos.y * 64);
		printf("new position x: %i\n", pos.x);
		printf("----------------------------------\n");
	}
	return (pos);
}