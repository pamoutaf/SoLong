/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:17:06 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/21 19:23:40 by pamoutaf         ###   ########.fr       */
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
	void	*empty;
	void	*wall;
	void	*end;
	void	*player;
}				t_sprite;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_mlx_data
{
	void	*win;
	void	*mlx;
	t_sprite	img;
	t_pos		position;
}				t_mlx_data;

void	parse_map(const char *filename, t_map_data *data);
int		key_hook(int keycode, t_mlx_data mlx_data);
void	png_to_win(void *mlx_ptr, t_sprite *sprite);
t_pos	png_to_map(void *mlx_ptr, t_map_data *data, void *win, t_sprite *sprite);
void	grab_pos_player(void *mlx_ptr, void *win, t_pos *pos);
int		move_left(void *mlx_ptr, void *win, t_sprite *sprite, t_pos *pos);

#endif