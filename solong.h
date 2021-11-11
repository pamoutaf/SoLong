/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:17:06 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/10 16:04:05 by pamoutaf         ###   ########.fr       */
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
}				t_list;

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


#endif