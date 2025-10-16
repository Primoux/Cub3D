#include "cub3d.h"
#include "mlx.h"
#include "mlx_management.h"

double	y_inter(t_data *data, double angle)
{
	double	x;
	double	y;
	double	x_step;
	double	y_step;
	int		pixel;

	x_step = TILE;
	y_step = TILE * tan(angle);
	x = floor(data->player->px / TILE) * TILE;
	pixel = balance_inter(angle, &x, &x_step, 1);
	y = data->player->py + (x - data->player->px) * tan(angle);
	if ((ray_dir(angle, 0) && y_step < 0) || (!ray_dir(angle, 0) && y_step > 0))
		y_step *= -1;
	while (!is_wall(data->map, x + pixel, y))
	{
		y += y_step;
		x += x_step;
	}
	data->ray->rx = x;
	data->ray->ry = y;
	return (sqrt(pow(y - data->player->py, 2) + pow(x - data->player->px, 2)));
}

double	x_inter(t_data *data, double angle)
{
	double	x_step;
	double	y_step;
	double	x;
	double	y;
	int		pixel;

	y_step = TILE;
	x_step = TILE / tan(angle);
	y = floor(data->player->py / TILE) * TILE;
	pixel = balance_inter(angle, &y, &y_step, 0);
	x = data->player->px + (y - data->player->py) / tan(angle);
	if ((ray_dir(angle, 1) && x_step < 0) || (!ray_dir(angle, 1) && x_step > 0))
		x_step *= -1;
	while (!is_wall(data->map, x, y + pixel))
	{
		x += x_step;
		y += y_step;
	}
	data->ray->rx = x;
	data->ray->ry = y;
	return (sqrt(pow(x - data->player->px, 2) + pow(y - data->player->py, 2)));
}

double	lazerizor(t_data *data, double angle)
{
	double	x_dist;
	double	y_dist;

	x_dist = x_inter(data, angle);
	y_dist = y_inter(data, angle);
	if (x_dist <= y_dist)
	{
		data->ray->rx_dist  = x_dist;
		return (x_dist);
	}
	data->ray->rx_dist  = y_dist;
	return (y_dist);
}

void	my_mlx_put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

//37 lines
void	raycaster(t_data *data)
{
	int		i;
	int		j;
	double	dist;
	double	corrected_dist;
	double	wall_height;
	int		wall_top;
	int		wall_bot;

	i = 0;
	data->ray->rad_fov = FOV * (M_PI / 180);
	data->ray->angle = (data->player->angle - (data->ray->rad_fov * 0.5));
	while (i < WIDTH)
	{
		norm_angle(&data->ray->angle);
		dist = lazerizor(data, data->ray->angle);
		corrected_dist = dist * cos(data->ray->angle - data->player->angle);
		if (corrected_dist <= 0)
			corrected_dist = 0.1;
		wall_height = (TILE * HEIGHT) / corrected_dist;
		if (wall_height > HEIGHT)
			wall_height = HEIGHT;
		wall_top = (HEIGHT - wall_height) / 2;
		wall_bot = wall_top + wall_height;
		j = 0;
		while (j < HEIGHT)
		{
			if (j < wall_top)
				my_mlx_put_pixel(data->img, i, j, data->texture->ceiling.val);
			else if (j < wall_bot)
				my_mlx_put_pixel(data->img, i, j, 0x000000);
			else
				my_mlx_put_pixel(data->img, i, j, data->texture->floor.val);
			j++;
		}
		data->ray->ray_dist = corrected_dist;
		data->ray->angle += data->ray->rad_fov / WIDTH;
		i++;
	}
}
