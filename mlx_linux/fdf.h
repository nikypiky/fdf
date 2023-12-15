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

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}t_data;

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
void	bresenhams(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2);
void	bresenhams_y(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2);
void	bresenhams_minus(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2);
void	bresenhams_y_minus(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2);


#endif
