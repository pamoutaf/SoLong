/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:49:40 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/29 14:03:53 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void load_img(void *mlx_ptr, t_sprite *sprite)
{
	int			width = 64;
	int			height = 64;

	sprite->sprite_wall = mlx_png_file_to_image(mlx_ptr, "./wall.png", &width, &height);
	sprite->sprite_empty = mlx_png_file_to_image(mlx_ptr, "./empty.png", &width, &height);
	sprite->sprite_end = mlx_png_file_to_image(mlx_ptr, "./end.png", &width, &height);
	sprite->sprite_player_front = mlx_png_file_to_image(mlx_ptr, "./front.png", &width, &height);
	sprite->sprite_player_left = mlx_png_file_to_image(mlx_ptr, "./left.png", &width, &height);
	sprite->sprite_player_right = mlx_png_file_to_image(mlx_ptr, "./right.png", &width, &height);
	sprite->sprite_player_back = mlx_png_file_to_image(mlx_ptr, "./back.png", &width, &height);
}

static void grab_pos_player(void *mlx_ptr, void *win, t_pos *pos)
{
	(void)mlx_ptr;
	(void)win;
	printf("position x: %d, position y: %d\n", pos->x, pos->y);
}

t_pos png_to_win(t_global *global)
{
	t_pos	player;
	t_pos	pos;
	
	pos.y = 0;
	while (pos.y < global->map_data->height)
	{
		pos.x = 0;
		while (pos.x < global->map_data->len)
		{
			if(global->map_data->map[pos.y][pos.x] == '0')
				mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_empty, pos.x * 64, pos.y * 64);
			if(global->map_data->map[pos.y][pos.x] == '1')
				mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_wall, pos.x * 64, pos.y * 64);
			if(global->map_data->map[pos.y][pos.x] == 'E')
				mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_end, pos.x * 64, pos.y * 64);
			if(global->map_data->map[pos.y][pos.x] == 'P')
			{
				mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_empty, pos.x * 64, pos.y * 64);
				mlx_put_image_to_window(global->mlx, global->win, global->img->sprite_player_front, pos.x * 64, pos.y * 64);
				grab_pos_player(global->mlx, global->win, &pos);
				player = pos;
			}
			pos.x++;
		}
		pos.y++;
	}
	return (player);
}
