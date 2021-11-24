/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:07:54 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/24 15:46:50 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int key_hook(int keycode, void *param)
{
	t_pos pos;
	t_global	*global;
	
	global = (t_global*)param;
	printf("keycode : %d\n", keycode);
	printf("key_hook pointer : %p\n", global->win);
	printf("Hello\n");
	pos = png_to_win(global->mlx, global->map_data, global->win, global->img);
	if (keycode == 13)
		move_vertical(global->map_data, &pos, 1);
	if (keycode == 53)
		exit(0);
	return (0);
}

int	check_wall(t_map_data *data, int x, int y)
{
	if (data->map[y][x] == 1)
		return (0);
	return (1);
}

void move_vertical(t_map_data *data, t_pos *pos, int direction)
{
	printf("move vertical\n");
	int	x;
	int	y;

	x = pos->x;
	y = pos->y;
	if (check_wall(data, x, y + direction))
	{
		pos->y += direction;
		printf("position y: %i\n", pos->y);
	}
}
