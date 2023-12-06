#include <stdio.h>
#include "mlx_linux/fdf.h"
#include "mlx_linux/mlx.h"

int	get_direction(int point_a, int point_b)
{
	if (point_a < point_b)
		return (-1);
	else
		return (1);
}

float	get_move_len(int Ax, int Ay, int Bx, int By)
{
	float	i;

	i = (float)(Ax - Bx) / (Ay - By);
	if (i < 0)
		return (-i);
	return (i);
}

void    join_points(void *mlx_ptr, void *win_ptr, int Ax, int Ay, int Bx, int By)
{
	float	Vx;
	float	Vy;

	Vx = 0;
	Vy = 0;
	while (Bx != Ax && By != Ay)
	{
		Vx += get_move_len(Ax, Ay, Bx, By);
		Vy += get_move_len(Ay, Ax, By, Bx);
		while (Vx > 1)
		{
			Bx += get_direction(Ax, Bx);
			Vx--;
			mlx_pixel_put(mlx_ptr, win_ptr, Bx, By, 0xff0000);
		}
		while (Vy > 1)
		{
			By += get_direction(Ay, By);
			Vy--;
			mlx_pixel_put(mlx_ptr, win_ptr, Bx, By, 0x00FFFF00);
		}
	}
}
