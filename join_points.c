/* #include <bits/types/cookie_io_functions_t.h> */
#include <stdio.h>
#include "mlx_linux/fdf.h"
#include "mlx_linux/mlx.h"

void	bresenhams(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	parameter;

	dx = x2 - x1;
	dy = y2 - y1;
	parameter = 2 * dy - dx;
	while (x1 <= x2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xff0000);
		x1++;
		if (parameter < 0)
			parameter += 2 * dy;
		else
		{
			parameter += 2 * (dy - dx);
			y1++;
		}
	}
}

void	bresenhams_y(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	parameter;

	dx = x2 - x1;
	dy = y2 - y1;
	parameter = 2 * dx - dy;
	while (y1 <= y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0x00ff00);
		y1++;
		if (parameter < 0)
			parameter += 2 * dx;
		else
		{
			parameter += 2 * (dx - dy);
			x1++;
		}
	}
}

void	bresenhams_minus(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	parameter;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0)
		dx *= -1;
	if (dy < 0)
		dy *= -1;
	parameter = 2 * dy - dx;
	while (x1 <= x2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xff00ff);
		x1++;
		if (parameter < 0)
			parameter += 2 * dy;
		else
		{
			parameter += 2 * (dy - dx);
			y1--;
		}
	}
}

void	bresenhams_y_minus(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	parameter;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0)
		dx *= -1;
	if (dy < 0)
		dy *= -1;
	parameter = 2 * dx - dy;
	while (y1 >= y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0x0000ff);
		y1--;
		if (parameter < 0)
			parameter += 2 * dx;
		else
		{
			parameter += 2 * (dx - dy);
			x1++;
		}
	}
}

void	join_points(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	float	slope;

	slope = (float)(y2 - y1) / (x2 - x1);
	if (x2 - x1 == 0)
		slope = 2;
	if (x1 < x2 && slope >= 0 && slope <= 1)
		bresenhams(mlx_ptr, win_ptr, x1, y1, x2, y2);
	if (x1 <= x2 && slope >= 1)
		bresenhams_y(mlx_ptr, win_ptr, x1, y1, x2, y2);
	if (x1 < x2 && slope <= 0 && slope >= -1)
		bresenhams_minus(mlx_ptr, win_ptr, x1, y1, x2, y2);
	if (x1 < x2 && slope <= -1)
		bresenhams_y_minus(mlx_ptr, win_ptr, x1, y1, x2, y2);
	if (x1 > x2 && slope >= 0 && slope < 1)
		bresenhams(mlx_ptr, win_ptr, x2, y2, x1, y1);
	if (x1 >= x2 && slope >= 1)
		bresenhams_y(mlx_ptr, win_ptr, x2, y2, x1, y1);
	if (x1 > x2 && slope < 0 && slope >= -1)
		bresenhams_minus(mlx_ptr, win_ptr, x2, y2, x1, y1);
	if (x1 > x2 && slope <= -1)
		bresenhams_y_minus(mlx_ptr, win_ptr, x2, y2, x1, y1);
}
