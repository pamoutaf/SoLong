/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:49:40 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/18 17:38:35 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void png_to_win(void *mlx_ptr, t_sprite *sprite)
{
	int			width = 64;
	int			height = 64;

	sprite->wall = mlx_png_file_to_image(mlx_ptr, "./wall.png", &width, &height);
	sprite->start = mlx_png_file_to_image(mlx_ptr, "./start.png", &width, &height);		
	sprite->end = mlx_png_file_to_image(mlx_ptr, "./end.png", &width, &height);
}

void png_to_map(void *mlx_ptr, t_map_data *data, void *win, t_sprite *sprite)
{
	int			y;
	int			x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->len)
		{
			if(data->map[y][x] == '1')
				mlx_put_image_to_window(mlx_ptr, win, sprite->wall, x * 64, y * 64);
			if(data->map[y][x] == 'E')
				mlx_put_image_to_window(mlx_ptr, win, sprite->end, x * 64, y * 64);
			if(data->map[y][x] == 'P')
				mlx_put_image_to_window(mlx_ptr, win, sprite->start, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
