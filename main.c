/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:20:45 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/16 23:34:10 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

int main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		i;
	t_map_data	data;
	t_sprite	sprite;
	
	if (argc != 2)
		return (-1);
	parse_map(argv[1], &data);
	mlx =  mlx_init();
	win = mlx_new_window(mlx, data.len * 64, data.height * 64, "test");
	mlx_key_hook(win, key_hook, 0);
	mlx_pixel_put(mlx, win, (data.len* 64)/2, (data.height * 64)/2, 0xFFFFFF);
	png_to_win(mlx, &sprite, &data);
	i = 0;
	if (data.map[i] == '1')
		mlx_put_image_to_window(mlx, win, sprite.wall, 0, 0);
	if (data.map[i] == '0')
	mlx_put_image_to_window(mlx, win, sprite.end, 64, 0);
	if (data.map[i] == 'E')
	mlx_put_image_to_window(mlx, win, sprite.start, 128, 0);
	mlx_loop(mlx);
}