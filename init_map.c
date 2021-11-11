/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:14:43 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/11/10 18:18:48 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
void	open_window()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "test");

	mlx_pixel_put(mlx, win, 640/2, 360/2, 0xFFFFFF);

	mlx_loop(mlx);
}

int	count_lines(const char *map)
{
	int			numlines;
	char		*buf;
	int			fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (-1);
	numlines = 0;
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		numlines++;
		free(buf);
		buf = get_next_line(fd);
	}
	return (numlines);
}

int main(int argc, char **argv)
{
	t_list	context;
	int		i;
	
	(void)argc;
	if (argc != 2)
		return (0);
	context.height = count_lines(argv[1]);
	printf("%i\n", context.height);
	context.map = malloc(sizeof(char *) * context.height);
	if (!context.map)
		return (0);
	context.fd = open(argv[1], O_RDONLY);
	if (context.fd < 0)
		return (0);
	i = 0;
	while (i < context.height)
		context.map[i++] = get_next_line(context.fd);
	context.len = ft_strlen(context.map[0]) - 1;
	printf("%i\n", context.len);
	printf("%s", context.map[0]);
}

// verifier que les lines ont mm longueurs