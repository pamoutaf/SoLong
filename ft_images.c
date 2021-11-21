/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:49:40 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/21 19:10:15 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void png_to_win(void *mlx_ptr, t_sprite *sprite)
{
	int			width = 64;
	int			height = 64;

	sprite->wall = mlx_png_file_to_image(mlx_ptr, "./wall.png", &width, &height);
	sprite->empty = mlx_png_file_to_image(mlx_ptr, "./empty.png", &width, &height);
	sprite->end = mlx_png_file_to_image(mlx_ptr, "./end.png", &width, &height);
	sprite->player = mlx_png_file_to_image(mlx_ptr, "./player.png", &width, &height);
}

void grab_pos_player(void *mlx_ptr, void *win, t_pos *pos)
{
	(void)mlx_ptr;
	(void)win;
	printf("position x: %d, position y: %d\n", pos->x, pos->y);
}

t_pos png_to_map(void *mlx_ptr, t_map_data *data, void *win, t_sprite *sprite)
{
	t_pos pos;
	t_pos player;

	pos.y = 0;
	while (pos.y < data->height)
	{
		pos.x = 0;
		while (pos.x < data->len)
		{
			if(data->map[pos.y][pos.x] == '0')
				mlx_put_image_to_window(mlx_ptr, win, sprite->empty, pos.x * 64, pos.y * 64);
			if(data->map[pos.y][pos.x] == '1')
				mlx_put_image_to_window(mlx_ptr, win, sprite->wall, pos.x * 64, pos.y * 64);
			if(data->map[pos.y][pos.x] == 'E')
				mlx_put_image_to_window(mlx_ptr, win, sprite->end, pos.x * 64, pos.y * 64);
			if(data->map[pos.y][pos.x] == 'P')
			{
				mlx_put_image_to_window(mlx_ptr, win, sprite->empty, pos.x * 64, pos.y * 64);
				mlx_put_image_to_window(mlx_ptr, win, sprite->player, pos.x * 64, pos.y * 64);
				grab_pos_player(mlx_ptr, win, &pos);
				player = pos;
			}
			pos.x++;
		}
		pos.y++;
	}
	return (player);
}
