#include "mlx_linux/mlx.h"
#include "mlx_linux/fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <mlx_int.h>

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	image_data	*img;
	int	i;
} t_data;


void	my_mlx_pixel_put(image_data *data, int x, int y, int color)
{
	char	*dst;

	printf("check 4\n");
	printf("%p\n", data->img);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
	/* i = 0; */
	if (keysym == 65362)
		data->i++;
	if (keysym == 65364)
		data->i--;
	printf("Pressed key: %d\n", data->i);
	/* mlx_clear_window(data->mlx_ptr, data->win_ptr); */
	/* mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->i, 100, 16711680); */
	printf("check 3\n");
	my_mlx_pixel_put(data->img, 100, 100, 16711680);
	printf("check 5\n");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img, 0, 0);
	return (0);
}

int main(void)
{
	t_data data;
	image_data	img;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	data.i = 0;
	data.img = &img;

	img.img = mlx_new_image(data.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	printf("&img = %p", &img);
	printf(" data.img = %p\n", data.img);

	my_mlx_pixel_put(&img, 1300, 100, 16711680);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);




	// Register key release hook
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
