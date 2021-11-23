/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:07:54 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/23 14:05:24 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int key_hook(int keycode, void *param)
{
	t_pos pos;
	t_mlx_data	*data;
	
	data = (t_mlx_data*)param;
	printf("keycode : %d\n", keycode);
	pos = png_to_map(data->mlx, data, data->win, data->img->player);
	if (keycode == 13)
		move_vertical(data, &pos, 1);
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

int move_vertical(t_map_data *data, t_pos *pos, int direction)
{
	printf("movevertical\n");
	int	x;
	int	y;

	x = pos->x;
	y = pos->y;
	if (check_wall(data, x, y + (64 * direction)))
	{
		pos->y += direction * 64;
		pos->y++;
		printf("position y: %i\n", pos->y);
	}
	return (pos->y);
}
