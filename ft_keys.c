/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:07:54 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/28 22:09:56 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int key_hook(int keycode, void *param)
{
	t_global	*global;
	
	global = (t_global*)param;
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

void	write_steps(t_global *global)
{
	{
		mlx_string_put(global->mlx, global->win, 10, 10, 0xFE6500, "test");
	}
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

void move_vertical(t_global *global, t_map_data *data, int direction)
{
	int		x;
	int		y;
	char	*add;
	
	x = global->pos.x;
	y = global->pos.y;
	add = "start";
	if (can_move(data, x, y + direction))
	{
		add = ft_itoa((global)->map_data->steps);
		if(global->map_data->map[y][x] == 'E')
			mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player, global->pos.x * 64, global->pos.y * 64);
		else
		{
			mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_empty, global->pos.x * 64, global->pos.y * 64);
			global->pos.y = global->pos.y +(direction);

			mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player, global->pos.x * 64, global->pos.y * 64);
			mlx_string_put(global->mlx, global->win, 10, 10, 0xFFFFFF, add);
			free(add);
			data->steps++;
		}
	}
}

void move_horizontal(t_global *global, t_map_data *data, int direction)
{
	int		x;
	int		y;
	char	*add;
	
	x = global->pos.x;
	y = global->pos.y;
	add = "start";
	if (can_move(data, x + direction, y))
	{
		add = ft_itoa((global)->map_data->steps);
		if(global->map_data->map[y][x] == 'E')
			mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player, global->pos.x * 64, global->pos.y * 64);
		else
		{
			mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_empty, global->pos.x * 64, global->pos.y * 64);
			global->pos.x = global->pos.x +(direction);
			mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player, global->pos.x * 64, global->pos.y * 64);
			mlx_string_put(global->mlx, global->win, 10, 10, 0xFFFFFF, add);
			free(add);
			data->steps++;
		}
	}
}