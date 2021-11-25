/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:20:45 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/25 15:45:09 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int main(int argc, char **argv)
{
	t_global	global;
	t_map_data	map_data;
	t_sprite	sprite;
	t_pos		pos;
	
	if (argc != 2)
		return (-1);
	global.map_data = &map_data;
	parse_map(argv[1], global.map_data);
	printf("map data main: %p\n", global.map_data);
	global.mlx = mlx_init();
	global.win = mlx_new_window(global.mlx, global.map_data->len * 64, global.map_data->height * 64, "test");
	global.img = &sprite;
	load_img(global.mlx, global.img);
	printf("test pointer : %p\n", global.img->sprite_player);
	pos = png_to_win(global.mlx, global.map_data, global.win, global.img);
	//printf("x: %d y: %d\n", pos.x, pos.y);
	mlx_hook(global.win, 2, 0, key_hook, &global);
	printf("-----\n");
	mlx_loop(global.mlx);
}
