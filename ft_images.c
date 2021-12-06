/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:49:40 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/12/06 23:11:15 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void load_img(void *mlx_ptr, t_sprite *s)
{
	int			w;
	int			h;
	
	h = 64;
	w = 64;
	s->wall = mlx_png_file_to_image(mlx_ptr, "./img/wall.png", &w, &h);
	s->empty = mlx_png_file_to_image(mlx_ptr, "./img/empty.png", &w, &h);
	s->end = mlx_png_file_to_image(mlx_ptr, "./img/end.png", &w, &h);
	s->face = mlx_png_file_to_image(mlx_ptr, "./img/front.png", &w, &h);
	s->p_left = mlx_png_file_to_image(mlx_ptr, "./img/left.png", &w, &h);
	s->p_right = mlx_png_file_to_image(mlx_ptr, "./img/right.png", &w, &h);
	s->back = mlx_png_file_to_image(mlx_ptr, "./img/back.png", &w, &h);
	s->coll = mlx_png_file_to_image(mlx_ptr, "./img/ring.png", &w, &h);
}

static void process_map_tile(t_global *g, t_pos pos, char tile_char)
{
	if (tile_char == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->img->empty, pos.x * 64, pos.y * 64);
	if (tile_char == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img->wall, pos.x * 64, pos.y * 64);
	if (tile_char == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img->end, pos.x * 64, pos.y * 64);
	if (tile_char == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img->empty, pos.x * 64, pos.y * 64);
		mlx_put_image_to_window(g->mlx, g->win, g->img->face, pos.x * 64, pos.y * 64);
		g->pos = pos;
	}
	if (tile_char == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img->coll, pos.x * 64, pos.y * 64);
		g->map_data->collectibles++;
	}	
}

void png_to_win(t_global *global)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < global->map_data->height)
	{
		pos.x = 0;
		while (pos.x < global->map_data->len)
		{
			process_map_tile(global, pos, global->map_data->map[pos.y][pos.x]);
			pos.x++;
		}
		pos.y++;
	}
}