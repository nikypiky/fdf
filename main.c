#include "mlx_linux/mlx.h"
#include "mlx_linux/fdf.h"
# include <stdio.h>
/* # include <conio.h> */
/* # include <graphics.h> */
/* void main( ) */
/* { */
/* int x,y,x1,y1,x2,y2,p,dx,dy; */
/* int gdriver=DETECT,gmode; */
/* initgraph(&gdriver,&gmode,"C:\\tc\\BGI:"); */
/* printf("\nEnter the x-coordinate of the first point ::"); */
/* scanf("%d",&x1); */
/* printf("\nEnter the y-coordinate of the first point ::"); */
/* scanf("%d",&y1); */
/* printf("\nEnter the x-coordinate of the second point ::"); */
/* scanf("%d",&x2); */
/* printf("\nEnter the y-coordinate of the second point ::"); */
/* scanf("%d",&y2); */
/* x=x1; */
/* y=y1; */
/* dx=x2-x1; */
/* dy=y2-y1; */
/* putpixel(x,y,2); */
/* p=(2dy-dx); */
/* while(x<=x2) */
/* { */
/* if(p<0) */
/* { */
/* x=x+1; */
/* p=2*x-dx; */
/* } */
/* else */
/* { */
/* x=x+1; */
/* y=y+1; */
/* p=p+2*dy; */
/* } */
/* putpixel(x,y,7); */
/* } */
/* getch(); */
/* closegraph(); */
/* } */
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int x1 = 500;
	int	x,y,dx,dy,p;
	int y1 = 500;
	int x2 = 700;
	int y2 = 600;
	// t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_pixel_put(mlx, mlx_win, x1, y1, 0x00ff00);
	mlx_pixel_put(mlx, mlx_win, x2, y2, 0x0000ff);

x=x1;
y=y1;
dx=x2-x1;
dy=y2-y1;
	mlx_pixel_put(mlx, mlx_win, x, y, 0x0000ff);
p=(2*dy-dx);
while(x<=x2)
{
if(p<0)
{
x=x+1;
p=2*x-dx;
}
else
{
x=x+1;
y=y+1;
p=p+2*dy;
}
	mlx_pixel_put(mlx, mlx_win, x, y, 0x0000ff);
}
	mlx_loop(mlx);
}



/* 	while (x2 < 750) */
/* 	{ */
/* 		join_points(mlx, mlx_win, x1, y1, x2, y2); */
/* 		x2++; */
/* 	} */
/* 	join_points(mlx, mlx_win, x1, y1, x2, y2); */
/* 	while (y2 < 750) */
/* 	{ */
/* 		y2++; */
/* 		join_points(mlx, mlx_win, x1, y1, x2, y2); */
/* 	} */
/* 	while (x2 > 250) */
/* 	{ */
/* 		x2--; */
/* 		join_points(mlx, mlx_win, x1, y1, x2, y2); */
/* 	} */
/* 	while (y2 > 250) */
/* 	{ */
/* 		y2--; */
/* 		join_points(mlx, mlx_win, x1, y1, x2, y2); */
/* 	} */
/* } */
