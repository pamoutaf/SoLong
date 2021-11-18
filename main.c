/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:20:45 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/18 17:14:46 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_map_data	data;
	t_sprite	sprite;
	
	if (argc != 2)
		return (-1);
	parse_map(argv[1], &data);
	mlx = mlx_init();
	win = mlx_new_window(mlx, data.len * 64, data.height * 64, "test");
	mlx_key_hook(win, key_hook, 0);
	png_to_win(mlx, &sprite);
	png_to_map(mlx, &data, win, &sprite);
	mlx_loop(mlx);
}