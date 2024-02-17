#include "mlx_linux/mlx.h"
#include "mlx_linux/fdf.h"
#include <stdio.h>


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int key_press(int keycode, void *param)
{
    printf("Key pressed! Keycode: %d\n", keycode);
    return 0;
}


int on_keypress(int keysym, int *data)
{
/* i = 0; */
	if (keysym == 65362)
		data++;
	if (keysym == 65364)
		data--;
	printf("Pressed keyx: %d\n", *data);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int	data;

	data = 100;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Hello world!");

	mlx_hook(mlx_win, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_key_hook(mlx_win, key_press, 0);
	mlx_loop(mlx);
}
