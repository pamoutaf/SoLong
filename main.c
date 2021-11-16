/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:20:45 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/16 11:10:53 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int main(int argc, char **argv)
{
	void *mlx;
	void *win;
	t_map_data	data;
	
	if (argc != 2)
		return (-1);
	parse_map(argv[1], &data);
	mlx =  mlx_init();
	win = mlx_new_window(mlx, data.len * 64, data.height * 64, "test");
	mlx_key_hook(win, key_hook, 0);
	mlx_pixel_put(mlx, win, (data.len* 64)/2, (data.height * 64)/2, 0xFFFFFF);
	mlx_loop(mlx);
}