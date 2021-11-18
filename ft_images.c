/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:49:40 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/16 23:34:34 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void png_to_win(void *mlx_ptr, t_sprite *sprite, t_map_data *data)
{
	int		i;
	int		j;
	int		width = 64;
	int		height = 64;
	
	i = 0;
	while (i < data->height)	
	{
		j = 0;
		while (j < data->len)
		{
			sprite->wall = mlx_png_file_to_image(mlx_ptr, "./wall.png", &width, &height);
			sprite->start = mlx_png_file_to_image(mlx_ptr, "./start.png", &width, &height);
			sprite->end = mlx_png_file_to_image(mlx_ptr, "./end.png", &width, &height);
			j++;
		}
		i++;
	}
}
