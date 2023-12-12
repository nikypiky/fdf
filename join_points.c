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

/* void    join_points(void *mlx_ptr, void *win_ptr, int Ax, int Ay, int Bx, int By) */
/* { */
/* 	int	Vx; */
/* 	int	Vy; */

/* 	Vx = 0; */
/* 	Vy = 0; */
/* 	while (Bx != Ax && By != Ay) */
/* 	{ */
/* 		Vx += get_move_len(Ax, Ay, Bx, By); */
/* 		Vy += get_move_len(Ay, Ax, By, Bx); */
/* 		while (Vx > 1) */
/* 		{ */
/* 			Bx += get_direction(Ax, Bx); */
/* 			Vx--; */
/* 			mlx_pixel_put(mlx_ptr, win_ptr, Bx, By, 0xff0000); */
/* 		} */
/* 		while (Vy > 1) */
/* 		{ */
/* 			By += get_direction(Ay, By); */
/* 			Vy--; */
/* 			mlx_pixel_put(mlx_ptr, win_ptr, Bx, By, 0x00FFFF00); */
/* 		} */
/* 	} */
/* } */

// void	join_points(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
// {
// 	// int	slope;

// 	// slope = (x2 - x1) / (y2 - y1);
// 	if (x1 < x2)
// 		bresenhams(mlx_ptr, win_ptr, x1, y1, x2, y2);
// 	if (x1 > x2)
// 		besenhams(mlx_ptr, win_ptr, x2, y2, x1, y1);
// }

void	bresenhams(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2)
{
	int	x;
	int	y;
	int	decision_parameter;
	int	slope_error;

	decision_parameter = 2 * (y2 - y1);
	// if (decision_parameter gc< 0)
	// 	decision_parameter *= -1;
	slope_error = decision_parameter - (x2 - x1);
	x = x1;
	y = y1;
	while (x != x2)
	{
		printf("x = %i y = %i\n", x, y);
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xff0000);
		slope_error += decision_parameter;
	    if (slope_error >= 0)
		{
            y++;
            slope_error -= 2 * (x2 - x1);
        }
		x++;
	}
}

// void bresenhams(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2) {
//     int dx = x2 - x1;
//     int dy = y2 - y1;

//     int x = x1;
//     int y = y1;

//     int decision_parameter = 2 * dy - dx;
//     int slope_error = decision_parameter;

//     while (x != x2) {
//         printf("x = %i y = %i\n", x, y);
//         mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xff0000);

//         x++;

//         slope_error += 2 * dy;

//         if (slope_error >= dx) {
//             y++;
//             slope_error -= 2 * dx;
//         }
//     }
// }
