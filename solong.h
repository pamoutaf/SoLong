/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:17:06 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/23 14:06:09 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include "srcs/get_next_line.h"
#include <stdio.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_sprite
{
	void	*empty;
	void	*wall;
	void	*end;
	void	*player;
}				t_sprite;

typedef struct s_list
{
	int		i;
	int		height;
	int		len;
	char	**map;
	int		fd;
}				t_map_data;

typedef struct s_mlx_data
{
	void		*win;
	void		*mlx;
	t_sprite	*img;
	t_map_data	*data;
	t_pos		*pos;
}				t_mlx_data;

void	parse_map(const char *filename, t_map_data *data);
int		key_hook(int keycode, void *param);
void	png_to_win(void *mlx_ptr, t_sprite *sprite);
t_pos	png_to_map(void *mlx_ptr, t_map_data *data, void *win, t_sprite *sprite);
int		move_left(t_pos *pos, int direction);
int		check_wall(t_map_data *data, int x, int y);
int		move_vertical(t_map_data *data, t_pos *pos, int direction);

#endif