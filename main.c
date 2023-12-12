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
	int x1 = 500;
	int y1 = 500;
	int x2 = 600;
	int y2 = 450;
	// t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_pixel_put(mlx, mlx_win, x1, y1, 0x00ff00);
	mlx_pixel_put(mlx, mlx_win, x2, y2, 0x0000ff);

	// join_points(mlx, mlx_win, x1, y1, x2, y2);
	/* bresenhams_y(mlx, mlx_win, x1, y1, x2, y2); */
	bresenhams_minus(mlx, mlx_win, x1, y1, x2, y2);
	mlx_loop(mlx);
}
