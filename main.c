/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:20:45 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/12/07 13:38:15 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int	main(int argc, char **argv)
{
	t_global	g;
	t_map_data	mdata;
	t_sprite	sprite;

	if (argc != 2)
		error_message("Please enter a map");
	g.mdata = &mdata;
	parse_map(argv[1], g.mdata);
	g.mlx = mlx_init();
	g.w = mlx_new_window(g.mlx, g.mdata->len * 64, g.mdata->h * 64, "SoLong");
	g.mdata->steps = 1;
	g.mdata->collectibles = 0;
	g.i = &sprite;
	load_img(g.mlx, g.i);
	png_to_win(&g);
	mlx_hook(g.w, 2, 0, key_hook, &g);
	mlx_loop(g.mlx);
}
