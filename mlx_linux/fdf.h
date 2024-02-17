/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nik <nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:29:15 by nik               #+#    #+#             */
/*   Updated: 2023/08/30 22:47:22 by nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define UP_KEY 65362
# define DOWN_KEY 65364
# define RIGHT_KEY 65363
# define LEFT_KEY 65361

/* typedef struct	s_data { */
/* 	void	*img; */
/* 	char	*addr; */
/* 	int	bits_per_pixel; */
/* 	int	line_length; */
/* 	int	endian; */
/* }t_data; */

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
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	get_screen_vector(screen *screen);

#endif
