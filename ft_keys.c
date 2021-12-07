/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:07:54 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/12/07 13:16:18 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int	key_hook(int keycode, void *param)
{
	t_global	*g;

	g = (t_global *)param;
	if (keycode == 13)
		move_back(g, g->mdata);
	if (keycode == 1)
		move_front(g, g->mdata);
	if (keycode == 0)
		move_left(g, g->mdata);
	if (keycode == 2)
		move_right(g, g->mdata);
	if (keycode == 53)
		exit(0);
	return (0);
}

void	move_right(t_global *g, t_map_data *data)
{
	int		x;
	int		y;
	char	*add;

	x = g->p.x;
	y = g->p.y;
	if (can_move(data, x + 1, y))
	{
		if (g->mdata->map[y][x] == 'E')
			mlx_put_image_to_window(g->mlx, g->w, g->i->f,
				g->p.x * 64, g->p.y * 64);
		add = ft_itoa(g->mdata->steps);
		mlx_put_image_to_window(g->mlx, g->w, g->i->wall, 0, 0);
		mlx_string_put(g->mlx, g->w, 10, 10, 0xFFFFFF, add);
		free(add);
		printf("total steps so far : %i\n", g->mdata->steps);
		g->mdata->steps++;
		mlx_put_image_to_window(g->mlx, g->w, g->i->e,
			g->p.x * 64, g->p.y * 64);
		g->p.x = g->p.x + 1;
		mlx_put_image_to_window(g->mlx, g->w, g->i->p_right,
			g->p.x * 64, g->p.y * 64);
	}
}

void	move_left(t_global *g, t_map_data *data)
{
	int		x;
	int		y;
	char	*add;

	x = g->p.x;
	y = g->p.y;
	if (can_move(data, x - 1, y))
	{
		if (g->mdata->map[y][x] == 'E')
			mlx_put_image_to_window(g->mlx, g->w, g->i->f,
				g->p.x * 64, g->p.y * 64);
		add = ft_itoa(g->mdata->steps);
		mlx_put_image_to_window(g->mlx, g->w, g->i->wall, 0, 0);
		mlx_string_put(g->mlx, g->w, 10, 10, 0xFFFFFF, add);
		free(add);
		printf("total steps so far : %i\n", g->mdata->steps);
		g->mdata->steps++;
		mlx_put_image_to_window(g->mlx, g->w, g->i->e,
			g->p.x * 64, g->p.y * 64);
		g->p.x = g->p.x - 1;
		mlx_put_image_to_window(g->mlx, g->w, g->i->p_left,
			g->p.x * 64, g->p.y * 64);
	}
}

void	move_front(t_global *g, t_map_data *data)
{
	int		x;
	int		y;
	char	*add;

	x = g->p.x;
	y = g->p.y;
	if (can_move(data, x, y + 1))
	{
		if (g->mdata->map[y][x] == 'E')
			mlx_put_image_to_window(g->mlx, g->w, g->i->f,
				g->p.x * 64, g->p.y * 64);
		add = ft_itoa(g->mdata->steps);
		mlx_put_image_to_window(g->mlx, g->w, g->i->wall, 0, 0);
		mlx_string_put(g->mlx, g->w, 10, 10, 0xFFFFFF, add);
		free(add);
		printf("total steps so far : %i\n", g->mdata->steps);
		g->mdata->steps++;
		mlx_put_image_to_window(g->mlx, g->w, g->i->e,
			g->p.x * 64, g->p.y * 64);
		g->p.y = g->p.y + 1;
		mlx_put_image_to_window(g->mlx, g->w, g->i->f,
			g->p.x * 64, g->p.y * 64);
	}
}

void	move_back(t_global *g, t_map_data *data)
{
	int		x;
	int		y;
	char	*add;

	x = g->p.x;
	y = g->p.y;
	if (can_move(data, x, y - 1))
	{
		if (g->mdata->map[y][x] == 'E')
			mlx_put_image_to_window(g->mlx, g->w, g->i->f,
				g->p.x * 64, g->p.y * 64);
		add = ft_itoa(g->mdata->steps);
		mlx_put_image_to_window(g->mlx, g->w, g->i->wall, 0, 0);
		mlx_string_put(g->mlx, g->w, 10, 10, 0xFFFFFF, add);
		free(add);
		printf("total steps so far : %i\n", g->mdata->steps);
		g->mdata->steps++;
		mlx_put_image_to_window(g->mlx, g->w, g->i->e,
			g->p.x * 64, g->p.y * 64);
		g->p.y = g->p.y - 1;
		mlx_put_image_to_window(g->mlx, g->w, g->i->back,
			g->p.x * 64, g->p.y * 64);
	}
}
