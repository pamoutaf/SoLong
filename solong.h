/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:17:06 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/12/07 15:07:16 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include "gnl/get_next_line.h"
# include <stdio.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_sprite
{
	void	*e;
	void	*wall;
	void	*end;
	void	*f;
	void	*p_left;
	void	*p_right;
	void	*back;
	void	*coll;
}				t_sprite;

typedef struct s_map_data
{
	int		i;
	int		h;
	int		len;
	char	**map;
	int		fd;
	int		steps;
	int		collectibles;
}				t_map_data;

typedef struct s_global
{
	void		*w;
	void		*mlx;
	t_sprite	*i;
	t_pos		p;
	t_map_data	*mdata;
}				t_global;

t_map_data	*parse_map(const char *filename, t_map_data *data);
int			key_hook(int keycode, void *param);
void		load_img(void *mlx_ptr, t_sprite *sprite);
void		png_to_win(t_global *global);
void		move_left(t_global *global, t_map_data *data);
void		move_right(t_global *global, t_map_data *data);
void		move_front(t_global *global, t_map_data *data);
void		move_back(t_global *global, t_map_data *data);
int			can_move(t_map_data *data, int x, int y);
void		move_vertical(t_global *global, t_map_data *data, int direction);
void		move_horizontal(t_global *global, t_map_data *data, int direction);
void		error_message(char *str);
void		ft_put_steps(t_global *global);
char		*ft_itoa(int n);
int			ft_putchar_fd(char c, int fd);
void		check_map_len(t_map_data *data);
void		check_one_map(t_map_data *data);
void		is_player(t_map_data *data);
void		is_exit(t_map_data *data);
void		check_map_character(t_map_data *data);
void		check_map_name(const char *str);
int			button_hook(void *param);

#endif