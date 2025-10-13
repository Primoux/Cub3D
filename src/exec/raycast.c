#include "cub3d.h"
#include "mlx.h"
#include "mlx_management.h"

double	y_inter(t_data *data, double angle)
{
	double x;
	double y;
	double x_step;
	double y_step;
	int pixel;

	x_step = TILE;
	y_step = TILE * tan(angle);
	x = floor(data->player->px / TILE) * TILE;
	pixel = balance_inter(angle, &x, &x_step, 1); //corriger angle x et x_step
	y = data->player->py + (x - data->player->px) * tan(angle);
	if ((ray_dir(angle, 0) && y_step < 0) || (!ray_dir(angle, 0) && y_step > 0)) //rediriger lazer de y_step du bon cote en fontion de l'angle (droite ou gauche du cercle trigo)
		y_step *= -1;
	while (!is_wall(data->map, x + pixel  , y))
	{
		printf("(fonction y_inter) [x + pixel] = %f [%d] | [y] = %f [%d]\n", x, (int)x + pixel, y, (int)y);
//		printf("(fonction y_inter) [xstep] = %f [%d] | [ystep] = %f [%d]\n", x_step, (int)x, y_step, (int)y);
		mlx_pixel_put(data->mlx, data->win, (int)x - 1 , (int)y, 0x00FF0000);
		mlx_pixel_put(data->mlx, data->win, (int)x  , (int)y, 0x00FF0000);
		mlx_pixel_put(data->mlx, data->win, (int)x + 1 , (int)y, 0x00FF0000);
		y += y_step;
		x += x_step;
		usleep(500);
	}
	data->ray->rx = x;
	data->ray->ry = y;
	return (sqrt(pow(y - data->player->py, 2) + pow(x - data->player->px, 2)));
}

double	x_inter(t_data *data, double angle)
{
	double x_step;
	double y_step;
	double x;
	double y;
	int pixel;

	y_step = TILE;
	x_step = TILE / tan(angle);
	y = floor(data->player->py / TILE) * TILE;
	pixel = balance_inter(angle, &y, &y_step, 0);
	printf("pixel = %d\n", pixel);
	x = data->player->px + (y - data->player->py) / tan(angle);
	if ((ray_dir(angle, 1) && x_step < 0) || (!ray_dir(angle, 1) && x_step > 0))
		x_step *= -1;
	while (!is_wall(data->map, x, y + pixel))
	{
		printf("(fonction x_inter) [x] = %f [%d] | [y] = %f [%d]\n", x, (int)x , y, (int)y);
//		printf("(fonction x_inter) boucle\n");
		mlx_pixel_put(data->mlx, data->win, (int)x - 1 , (int)y, 0x00FF0000);
		mlx_pixel_put(data->mlx, data->win, (int)x  , (int)y, 0x00FF0000);
		mlx_pixel_put(data->mlx, data->win, (int)x + 1 , (int)y, 0x00FF0000);
		x += x_step;
		y += y_step;
//		usleep(500);
	}
	data->ray->rx = x;
	data->ray->ry = y;
	return (sqrt(pow(x -data->player->px , 2) + pow(y -data->player->py, 2)));
}

void	lazerizor(t_data *data, double angle)
{
	double x;
	double y;
	bool wall;

	wall = false;
	x = data->player->px;
	y = data->player->py;
	printf("(fonction lazerizor) %f\n\n", angle / M_PI);

	y_inter(data,  angle);
	x_inter(data,  angle);

}


void	raycaster(t_data *data)
{
	int i;
	double rad_fov;

	i = 0;
	rad_fov = FOV * (M_PI / 180);
//	printf("rat des fave = %f\n", rad_fov);
	data->ray->angle = (data->player->angle - (rad_fov * 0.5));
//	printf("(fonction raycaster) ray charles angle = %f\n", data->ray->angle);

	while (i < WIDTH)
	{
		norm_angle(&data->ray->angle);
//		printf("(fonction raycaster) pls ray angle = %f\n", data->ray->angle);
//		printf("(fonction raycaster) i = [%d]\n", i);
		lazerizor(data, data->ray->angle);
		data->ray->angle += rad_fov / WIDTH;
		i++;
	}
}
