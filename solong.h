/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:17:06 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/18 17:11:09 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include "srcs/get_next_line.h"
#include <stdio.h>

typedef struct s_list
{
	int		i;
	int		height;
	int		len;
	char	**map;
	int		fd;
}				t_map_data;

typedef struct s_sprite
{
	void	*start;
	void	*wall;
	void	*end;
}				t_sprite;



typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char	**map;
	t_pos	size;
}	t_map;

void	parse_map(const char *filename, t_map_data *data);
int		key_hook(int keycode, void *param);
void	png_to_win(void *mlx_ptr, t_sprite *sprite);
void png_to_map(void *mlx_ptr, t_map_data *data, void *win, t_sprite *sprite);

#endif