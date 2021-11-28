/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:20:45 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/28 21:46:40 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int main(int argc, char **argv)
{
	t_global	global;
	t_map_data	map_data;
	t_sprite	sprite;	
	if (argc != 2)
		return (-1);
	global.map_data = &map_data;
	parse_map(argv[1], global.map_data);
	global.mlx = mlx_init();
	global.win = mlx_new_window(global.mlx, global.map_data->len * 64, global.map_data->height * 64, "SoLong");
	global.img = &sprite;
	load_img(global.mlx, global.img);
	global.pos = png_to_win(&global);
	//printf("x: %d y: %d\n", pos.x, pos.y);
	mlx_hook(global.win, 2, 0, key_hook, &global);
	mlx_loop(global.mlx);
}
