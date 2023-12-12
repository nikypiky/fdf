#include "mlx_linux/mlx.h"
#include "mlx_linux/fdf.h"
#include <stdio.h>


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int x1 = 100;
	int y1 = 100;
	int x2 = 200;
	int y2 = 1000;
	// t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_pixel_put(mlx, mlx_win, x1, y1, 0x00ff00);
	mlx_pixel_put(mlx, mlx_win, x2, y2, 0x00ff00);

	// join_points(mlx, mlx_win, x1, y1, x2, y2);
	bresenhams(mlx, mlx_win, x1, y1, x2, y2);
	mlx_loop(mlx);
}
