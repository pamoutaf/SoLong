/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protections_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:04:48 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/12/07 13:36:57 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"

void	check_map_character(t_map_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] != 'P' && data->map[j][i] != '1'
				&& data->map[j][i] != '0' && data->map[j][i] != 'E'
				&& data->map[j][i] != 'C')
			{
				printf("%c\n", data->map[j][i]);
				error_message("Wrong character in map :");
			}
			i++;
		}
		j++;
	}
}

void	check_map_name(const char *str)
{
	int	i;

	i = ft_strlen(str);
	i--;
	if (str[i] == 'r')
	{
		i--;
		if (str[i] == 'e')
		{
			i--;
			if (str[i] == 'b')
			{
				i--;
				if (str[i] == '.')
					return ;
			}
		}
	}
	else
		error_message("Please write a .ber extension");
}
