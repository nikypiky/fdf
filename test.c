
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

void    points(int Ax, int Ay, int Bx, int By)
{
	float	Vx;
	float	Vy;

	Vx = 0;
	Vy = 0;
	while (Bx != Ax || By != Ay)
	{
		Vx += get_move_len(Ax, Ay, Bx, By);
		Vy += get_move_len(Ay, Ax, By, Bx);
		while (Vx > 1)
		{
			Bx += get_direction(Ax, Bx);
			Vx--;
			printf("Bx = %i ", Bx);
		}
		/* printf("\n"); */
		while (Vy > 1)
		{
			By += get_direction(Ay, By);
			Vy--;
			printf("By = %i ", By);
		}
		printf("\n");
	}
}

void	test_besenhams(int x1, int y1, int x2, int y2)
{
	int	x;
	int	y;
	int	decision_parameter;
	int	slope_error;

	decision_parameter = 2 * (y2 - y1);
	slope_error = decision_parameter - (x2 - x1);
	x = x1;
	y = y1;
	while (x != x2)
	{
		printf("x = %i y = %i\n", x, y);
		slope_error += decision_parameter;
	    if (slope_error >= 0)
		{
            y++;
            slope_error -= 2 * (x2 - x1);
        }
		x++;
	}
}

int	main(void)
{
	test_besenhams(3, 2, 15, 5);
	test_besenhams(10, 12, 8, 1);
	points(15, 5, 3, 2);
}
