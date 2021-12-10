/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:49:40 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/12/10 18:29:33 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void	load_img(void *mlx_ptr, t_sprite *s)
{
	int			w;
	int			h;

	h = 64;
	w = 64;
	s->wall = mlx_png_file_to_image(mlx_ptr, "./img/wall.png", &w, &h);
	s->e = mlx_png_file_to_image(mlx_ptr, "./img/empty.png", &w, &h);
	s->end = mlx_png_file_to_image(mlx_ptr, "./img/end.png", &w, &h);
	s->f = mlx_png_file_to_image(mlx_ptr, "./img/front.png", &w, &h);
	s->p_left = mlx_png_file_to_image(mlx_ptr, "./img/left.png", &w, &h);
	s->p_right = mlx_png_file_to_image(mlx_ptr, "./img/right.png", &w, &h);
	s->back = mlx_png_file_to_image(mlx_ptr, "./img/back.png", &w, &h);
	s->coll = mlx_png_file_to_image(mlx_ptr, "./img/ring.png", &w, &h);
	if (!s->wall || !s->e || !s->end || !s->f || !s->p_left || !s->p_right
		|| !s->back || !s->coll)
		error_message("Failed to load image");
}

static void	process_map_tile(t_global *g, t_pos po, char tile_char)
{
	if (tile_char == '0')
		mlx_put_image_to_window(g->mlx, g->w, g->i->e, po.x * 64, po.y * 64);
	if (tile_char == '1')
		mlx_put_image_to_window(g->mlx, g->w, g->i->wall, po.x * 64, po.y * 64);
	if (tile_char == 'E')
		mlx_put_image_to_window(g->mlx, g->w, g->i->end, po.x * 64, po.y * 64);
	if (tile_char == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->w, g->i->e, po.x * 64, po.y * 64);
		mlx_put_image_to_window(g->mlx, g->w, g->i->f, po.x * 64, po.y * 64);
		g->p = po;
	}
	if (tile_char == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->w, g->i->coll, po.x * 64, po.y * 64);
		g->mdata->collectibles++;
	}	
}

void	png_to_win(t_global *global)
{
	t_pos	p;

	p.y = 0;
	while (p.y < global->mdata->h)
	{
		p.x = 0;
		while (p.x < global->mdata->len)
		{
			process_map_tile(global, p, global->mdata->map[p.y][p.x]);
			p.x++;
		}
		p.y++;
	}
}
