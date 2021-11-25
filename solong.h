/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:17:06 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/25 18:33:02 by pamoutaf         ###   ########.fr       */
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
	void	*sprite_empty;
	void	*sprite_wall;
	void	*sprite_end;
	void	*sprite_player;
}				t_sprite;

typedef struct s_map_data
{
	int		i;
	int		height;
	int		len;
	char	**map;
	int		fd;
}				t_map_data;

typedef struct s_global
{
	void		*win;
	void		*mlx;
	t_sprite	*img;
	t_pos		*pos;
	t_map_data	*map_data;
}				t_global;
//TODO (paula 24 nov): makefile headers dependencies
t_map_data	*parse_map(const char *filename, t_map_data *data);
int			key_hook(int keycode, void *param);
void		load_img(void *mlx_ptr, t_sprite *sprite);
t_pos		png_to_win(void *mlx_ptr, t_map_data *data, void *win, t_sprite *sprite);
int			move_left(t_pos *pos, int direction);
int			check_wall(t_map_data *data, int x, int y);
void		move_vertical(t_global *global, t_map_data *data, int direction);
void		move_horizontal(t_global *global, t_map_data *data, int direction);


#endif