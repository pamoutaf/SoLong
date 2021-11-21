/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:07:54 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/21 19:28:06 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int key_hook(int keycode, t_mlx_data mlx_data)
{
	
	printf("keycode : %d\n", keycode);
	if (keycode == 0)
		move_left(mlx_data.mlx, mlx_data.win, mlx_data.img.player, mlx_data.position.x);
	if (keycode == 53)
		exit(0);
	return (0);
}

int move_left(void *mlx_ptr, void *win, t_sprite *sprite, t_pos *pos)
{
	grab_pos_player(mlx_ptr, win, pos);
	if (keycode == 0)
	{
		printf("value of pos->x : %d\n", pos->x);
		pos->x = pos->x - 64;
		printf("new value of pos->x : %d\n", pos->x);
		mlx_put_image_to_window(mlx_ptr, win, sprite->player, pos->x, pos->y);
		printf("new value of pos->x : %d\n", pos->x);
	}
	return (0);
}

void move_right()
{
	
}

void move_up()
{
	
}

void move_down()
{
	
}
