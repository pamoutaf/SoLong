#include "mlx.h"

void	open_window()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "test");

	mlx_pixel_put(mlx, win, 640/2, 360/2, 0xFFFFFF);

	mlx_loop(mlx);
}

int main(int argc, char **argv)
{
	
}