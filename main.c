#include "mlx_linux/mlx.h"
#include "mlx_linux/fdf.h"
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	static int	i = 0;

	/* i = 0; */
	if (keysym == 65362)
		i++;
	if (keysym == 65364)
		i--;
	printf("Pressed key: %d\n", i);
	return (0);
}

int main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
