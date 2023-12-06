#include <stdio.h>

void    join_points(int ax, int ay, int bx, int by)
{
	float	vx;
	float	vy;

	vx = (float)(ax - bx) / (ay - by);
	vy = (float)(ay - by) / (ax - bx);

	while (ax != bx && ay != by)
	{
		if (ax != bx)
			bx = (float)bx + vx;
		if (ay != by)
			by = (float)by + vy;
		printf("ax = %i, ay = %i\n", ax, ay);
	}
}

