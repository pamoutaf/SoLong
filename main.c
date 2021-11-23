/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:20:45 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/23 14:04:38 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int main(int argc, char **argv)
{
	t_mlx_data	mlx_data;
	t_map_data	data;
	t_sprite	sprite;
	t_pos		pos;
	
	if (argc != 2)
		return (-1);
	parse_map(argv[1], &data);
	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, data.len * 64, data.height * 64, "test");
	png_to_win(mlx_data.mlx, &sprite);
	pos = png_to_map(mlx_data.mlx, &data, mlx_data.win, &sprite);
	printf("x: %d y: %d\n", pos.x, pos.y);
	mlx_hook(mlx_data.win, 2, 0, key_hook, &mlx_data);
	printf("-----\n");
	printf("-----\n");
	printf("data pointer : %p\n", mlx_data.mlx);
	mlx_loop(mlx_data.mlx);
}
