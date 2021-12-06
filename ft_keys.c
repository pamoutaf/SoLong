/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:07:54 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/12/06 23:22:07 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int key_hook(int keycode, void *param)
{
	t_global	*g;
	
	g = (t_global*)param;
	if (keycode == 13)
		move_back(g, g->map_data);
	if (keycode == 1)
		move_front(g, g->map_data);
	if (keycode == 0)
		move_left(g, g->map_data);
	if (keycode == 2)
		move_right(g, g->map_data);
	if (keycode == 53)
		exit(0);
	return (0);
}

void move_right(t_global *g, t_map_data *data)
{
	int		x;
	int		y;
	char	*add;
	
	x = g->pos.x;
	y = g->pos.y;
	if (can_move(data, x + 1, y))
	{
		if (g->map_data->map[y][x] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->img->face, g->pos.x * 64, g->pos.y * 64);
		add = ft_itoa(g->map_data->steps);
		mlx_put_image_to_window(g->mlx, g->win, g->img->wall, 0, 0);
		mlx_string_put(g->mlx, g->win, 10, 10, 0xFFFFFF, add);
		free(add);
		printf("total steps so far : %i\n", g->map_data->steps);
		g->map_data->steps++;
		mlx_put_image_to_window(g->mlx, g->win, g->img->empty, g->pos.x * 64, g->pos.y * 64);
		g->pos.x = g->pos.x + 1;
		mlx_put_image_to_window(g->mlx, g->win, g->img->p_right, g->pos.x * 64, g->pos.y * 64);
	}
}

void move_left(t_global *g, t_map_data *data)
{
	int		x;
	int		y;
	char	*add;
	
	x = g->pos.x;
	y = g->pos.y;
	
	if (can_move(data, x - 1, y))
	{
		if (g->map_data->map[y][x] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->img->face, g->pos.x * 64, g->pos.y * 64);
		add = ft_itoa(g->map_data->steps);
		mlx_put_image_to_window(g->mlx, g->win, g->img->wall, 0, 0);
		mlx_string_put(g->mlx, g->win, 10, 10, 0xFFFFFF, add);
		free(add);
		printf("total steps so far : %i\n", g->map_data->steps);
		g->map_data->steps++;
		mlx_put_image_to_window(g->mlx, g->win, g->img->empty, g->pos.x * 64, g->pos.y * 64);
		g->pos.x = g->pos.x - 1;
		mlx_put_image_to_window(g->mlx, g->win, g->img->p_left, g->pos.x * 64, g->pos.y * 64);
	}
}

void move_front(t_global *g, t_map_data *data)
{
	int		x;
	int		y;
	char	*add;
	
	x = g->pos.x;
	y = g->pos.y;
	if (can_move(data, x, y + 1))
	{
		if(g->map_data->map[y][x] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->img->face, g->pos.x * 64, g->pos.y * 64);
		add = ft_itoa(g->map_data->steps);
		mlx_put_image_to_window(g->mlx, g->win, g->img->wall, 0, 0);
		mlx_string_put(g->mlx, g->win, 10, 10, 0xFFFFFF, add);
		free(add);
		printf("total steps so far : %i\n", g->map_data->steps);
		g->map_data->steps++;
		mlx_put_image_to_window(g->mlx, g->win, g->img->empty, g->pos.x * 64, g->pos.y * 64);
		g->pos.y = g->pos.y + 1;
		mlx_put_image_to_window(g->mlx, g->win, g->img->face, g->pos.x * 64, g->pos.y * 64);
	}
}

void move_back(t_global *g, t_map_data *data)
{
	int		x;
	int		y;
	char	*add;
	
	x = g->pos.x;
	y = g->pos.y;
	if (can_move(data, x, y - 1 ))
	{
		if(g->map_data->map[y][x] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->img->face, g->pos.x * 64, g->pos.y * 64);
		add = ft_itoa(g->map_data->steps);
		mlx_put_image_to_window(g->mlx, g->win, g->img->wall, 0, 0);
		mlx_string_put(g->mlx, g->win, 10, 10, 0xFFFFFF, add);
		free(add);
		printf("total steps so far : %i\n", g->map_data->steps);
		g->map_data->steps++;
		mlx_put_image_to_window(g->mlx, g->win, g->img->empty, g->pos.x * 64, g->pos.y * 64);
		g->pos.y = g->pos.y - 1;
		mlx_put_image_to_window(g->mlx, g->win, g->img->back, g->pos.x * 64, g->pos.y * 64);
	}
}