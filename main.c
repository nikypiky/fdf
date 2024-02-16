#include "mlx_linux/mlx.h"
#include "mlx_linux/fdf.h"
#include <stdio.h>


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int key_press(int keycode, void *param)
{
    printf("Key pressed! Keycode: %d\n", keycode);
    return 0;
}

int	move_point(int keycode, void *param)
{
	int*	point = (int *)param;

	if (keycode == UP_KEY)
	{
		point[0] += 50;
		printf("%i\n", point[0]);
	}
	return (0);
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int	a[] = {400, 500};
	int	b[] = {1000, 1000};
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Hello world!");

	screen	screen;
	point	plane;
	point	viewer;
	plane.x = 2058;
	plane.y = 0;
	plane.z = 0;
	viewer.x = 0;
	viewer.y = 0;
	viewer.z = 0;
	screen.plane = plane;
	screen.viewer = viewer;
	get_screen_vector(&screen);
	mlx_key_hook(mlx_win, move_point, &a);
	join_points(mlx, mlx_win, a[0], a[1], b[0], b[1]);
	mlx_loop(mlx);
}
