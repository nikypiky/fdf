#include <stdio.h>

void    join_points(int Ax, int Ay, int Bx, int By)
{
	float	Vx;
	float	Vy;
	/* float	Nx; */
	/* float	Ny; */
	/* float	move_x; */
	/* float	move_y; */

	/* Nx = Bx; */
	/* Ny = By; */

	Vx = 0;
	Vy = 0;
	while (Bx != Ax && By != Ay)
	{
		Vx += (float)(Ax - Bx) / (Ay - By);
		Vy += (float)(Ay - By) / (Ax - Bx);
		while (Vx > 1)
		{
			Bx++;
			Vx--;
			printf("Bx = %i\n", Bx);
		}
		while (Vy > 1)
		{
			By++;
			Vy--;
			printf("By = %i\n", By);

		}
	}
}
