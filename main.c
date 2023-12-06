#include "mlx_linux/mlx.h"
#include "mlx_linux/fdf.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	join_points(9, -12, 5, -2);
	/* int i = 5; */
	/* float temp; */
	/* float j = 6.3; */
	/* temp = i + j; */

	/* printf("%f %i", temp, (int)temp); */
}
