#include <stdio.h>
#include "mlx_linux/fdf.h"
#include "mlx_linux/mlx.h"

void	bresenhams(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	parameter;

	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	parameter = 2 * dy - dx;

	while (x <= x2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xff0000);
		x++;
		if (parameter < 0)
			parameter += 2 * dy;
		else
		{
			parameter += 2 * (dy - dx);
			y++;
		}
	}
}

void	bresenhams_y(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	parameter;

	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	parameter = 2 * dx - dy;

	while (y <= y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00ff00);
		y++;
		if (parameter < 0)
			parameter += 2 * dx;
		else
		{
			parameter += 2 * (dx - dy);
			x++;
		}
	}
}

void	bresenhams_minus(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	parameter;

	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0)
		dx *= -1;
	if (dy < 0)
		dy *= -1;
	parameter = 2 * dy - dx;

	while (x <= x2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xff0000);
		x++;
		if (parameter < 0)
			parameter += 2 * dy;
		else
		{
			parameter += 2 * (dy - dx);
			y++;
		}
	}
}
