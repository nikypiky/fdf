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

image_data* create_frame(t_data data)
{
	image_data *img;
	printf("test2\n");
	if (data.img)
		mlx_destroy_image(data.mlx_ptr, data.img->img);
	img->img = mlx_new_image(data.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	return (img);
}


int on_keypress(int keysym, t_data *data)
{
	if (keysym == 65362)
		data->i++;
	if (keysym == 65364)
		data->i--;

	printf("Pressed key: %d\n", data->i);
	data->img = create_frame(*data);
	printf("test 1\n");
	my_mlx_pixel_put(data->img, data->i, 100, 16711680);
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
	/* data.img = &img; */

	/* img.img = mlx_new_image(data.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT); */
	/* img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian); */

	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);

	printf("destroy test\n");
	/* mlx_destroy_image(data.mlx_ptr, img.img); */
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
