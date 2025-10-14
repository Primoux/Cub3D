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
	while (!is_wall(data->map, x  + pixel  , y))
	{
		// printf("(fonction y_inter) [x + pixel] = %f [%d] | [y] = %f [%d]\n", x, (int)x + pixel, y, (int)y);
		// printf("(fonction y_inter) [xstep] = %f [%d] | [ystep] = %f [%d]\n", x_step, (int)x, y_step, (int)y);
		// mlx_pixel_put(data->mlx, data->win, (int)x  , (int)y, 0x00FF0000);
		y += y_step;
		x += x_step;
		// usleep(500);
	}
	// mlx_pixel_put(data->mlx, data->win, (int)x  , (int)y, 0x000000FF);
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
	// printf("pixel = %d\n", pixel);
	x = data->player->px + (y - data->player->py) / tan(angle);
	if ((ray_dir(angle, 1) && x_step < 0) || (!ray_dir(angle, 1) && x_step > 0))
		x_step *= -1;
	while (!is_wall(data->map, x, y + pixel))
	{
		// printf("(fonction x_inter) [x] = %f [%d] | [y] = %f [%d]\n", x, (int)x , y, (int)y);
		// printf("(fonction x_inter) boucle\n");
		// mlx_pixel_put(data->mlx, data->win, (int)x  , (int)y, 0x00FF0000);
		x += x_step;
		y += y_step;
		// usleep(500);
	}
	// mlx_pixel_put(data->mlx, data->win, (int)x  , (int)y, 0x000000FF);
	data->ray->rx = x;
	data->ray->ry = y;
	return (sqrt(pow(x -data->player->px , 2) + pow(y -data->player->py, 2)));
	return ((data->ray->rx - data->player->px) / cos(angle)); //pour corriger le fish-eyes pour y_inter
}
double	lazerizor(t_data *data, double angle)
{

	double x_dist;
	double y_dist;

	// printf("(fonction lazerizor) %f\n\n", angle / M_PI);
	y_dist = y_inter(data,  angle);
	x_dist = x_inter(data,  angle);
	if (y_dist < x_dist)
		return (y_dist);
	return (x_dist);
}


void my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
    char    *pixel;

    // Sécurité : vérifier que x et y sont dans les bornes
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;

    pixel = data->img->addr + (y * data->img->line_length + x * (data->img->bpp / 8));
    *(unsigned int *)pixel = color;
}

void	raycaster(t_data *data)
{
	int		i;
	int		j;
	double	rad_fov;
	double	dist;
	double	correct_dist;

	i = 0;
	rad_fov = FOV * (M_PI / 180);
	data->ray->angle = (data->player->angle - (rad_fov * 0.5));
	while (i < WIDTH)
	{
		j = 0;
		norm_angle(&data->ray->angle);
		dist = lazerizor(data, data->ray->angle);
		correct_dist = dist * cos(data->ray->angle - data->player->angle);
		while (j < HEIGHT)
		{
			if (j < correct_dist)
				my_mlx_put_pixel(data, i, j, 0x00FF0000);
			else if (j > HEIGHT - correct_dist)
				my_mlx_put_pixel(data, i, j, 0x000000FF);
			else
				my_mlx_put_pixel(data, i, j, 0x00000000);
			j++;
		}
		data->ray->ray_dist = correct_dist;
		data->ray->angle += rad_fov / WIDTH;
		i++;
	}
}
