#ifndef FDF_H
# define FDF_H

# define UP_KEY 65362
# define DOWN_KEY 65364
# define RIGHT_KEY 65363
# define LEFT_KEY 65361
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef struct	image_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	image_data;

typedef struct Point {
	int	x;
	int	y;
	int	z;
	int	screen_x;
	int	screen_y;
} point;

typedef struct Plane {
	point	viewer;
	point	plane;
	int		vector[3];
} screen;

void	join_points(void *mlx_ptr, void *win_ptr, int ax, int ay, int bx, int by);
/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color); */
void	get_screen_vector(screen *screen);

#endif
