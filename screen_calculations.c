#include "mlx_linux/mlx.h"
#include "mlx_linux/fdf.h"
#include <stdio.h>

void	get_screen_vector(screen *screen)
{
	screen->vector[0] = screen->plane.x - screen->viewer.x;
	screen->vector[1] = screen->plane.y - screen->viewer.y;
	screen->vector[2] = screen->plane.z - screen->viewer.z;
}

// void	move_viewer(int keycode, void *param)
// {
// 	if key
// }
