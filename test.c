#include "mlx_linux/fdf.h"
#include "mlx_linux/mlx.h"

float	intersection_x(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	float	x;

	x =  ((float)(x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4));
	x = x / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
	return (x);
}

float intersection_y(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	float	y;

	y = 1 * ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4));
	y = y / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
	return (y);
}

float	intercept(float x1, float y1, float x2, float y2)
{
	float	x;
	float	b;
	float	m;

	m = (float)(y2 - y1) / (x2 - x1);
	b = y1 - m * x1;
	x = (300 - b) / m;
	return (x);
}

void	plane_intersect(point *A, point *B)
{
	int	vector_AB[3];

	vector_AB[0] = B->x - A->x;
	vector_AB[1] = B->y - A->y;
	vector_AB[2] = B->z - A->z;
	A->screen_x = A->x + vector_AB[0] * 5 / 8;
	A->screen_y = A->z + vector_AB[2] * 5 / 8;
}

int main(void)
{
	point	A;
	point	B;

	A.x = 400;
	A.y = 300;
	A.z = 100;
	B.x = 1000;
	B.y = 0;
	B.z = 1000;
	plane_intersect(&A, &B);
	printf("x = %i, y = %i\n", A.screen_x, A.screen_y);
}
