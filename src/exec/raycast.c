#include "cub3d.h"
#include "mlx_management.h"

double	y_inter(t_data *data, double angle, double *hit_x, double *hit_y)
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
	*hit_x = x;
	*hit_y = y;
	return (sqrt(pow(y - data->player->py, 2) + pow(x - data->player->px, 2)));
}

double	x_inter(t_data *data, double angle, double *hit_x, double *hit_y)
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
	*hit_x = x; // point impact mur X;
	*hit_y = y; // point d'impact mur Y
	return (sqrt(pow(x - data->player->px, 2) + pow(y - data->player->py, 2)));
}

double	lazerizor(t_data *data, double angle)
{
	double	x_dist;
	double	y_dist;
	double	x_hit_x;
	double	y_hit_y;
	double	y_hit_x;
	double	x_hit_y;

	x_dist = x_inter(data, angle, &x_hit_x, &x_hit_y);
	y_dist = y_inter(data, angle, &y_hit_x, &y_hit_y);
	if (x_dist <= y_dist)
	{
		data->ray->flag = 'x';       // mur horizontal touche
		data->ray->rx_dist = x_dist; // distance a l’horizontale
		data->ray->ry_dist = y_dist; // distance a la verticale
		data->ray->hit_x = x_hit_x;  // point d’impact exact
		data->ray->hit_y = x_hit_y;  // same
		return (x_dist);
	}
	else
	{
		data->ray->flag = 'y'; // pareil pour y
		data->ray->rx_dist = x_dist;
		data->ray->ry_dist = y_dist;
		data->ray->hit_x = y_hit_x;
		data->ray->hit_y = y_hit_y;
		return (y_dist);
	}
}

void	my_mlx_put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	print_texture(t_data *data, int i, int j)
{
	double			tex_y;
	double			tex_x;
	unsigned int	color;
	t_img			*wall;

	if (data->ray->flag == 'x')
	{
		tex_x = fmod(data->ray->hit_x, TILE);
		if (tex_x < 0)
			tex_x += TILE;
		tex_x /= TILE;

		if (!ray_dir(data->ray->angle, 0))
		{
			wall = data->texture->n_wall;
		}
		else
		{
			tex_x = 1 - tex_x;
			wall = data->texture->s_wall;
		}
	}
	else
	{
		tex_x = fmod(data->ray->hit_y, TILE);
		if (tex_x < 0)
			tex_x += TILE;
		tex_x /= TILE;
		if (ray_dir(data->ray->angle, 1))
		{
			wall = data->texture->w_wall;
		}
		else
		{
			tex_x = 1 - tex_x;
			wall = data->texture->e_wall;
		}
	}

	tex_y = (double)((j - data->ray->rwall_top) * wall->height / data->ray->rwall_height);
	color = *(unsigned int *)(wall->addr + ((int)tex_y
			* wall->line_length + (int)(tex_x * wall->width) * (wall->bpp / 8)));
	my_mlx_put_pixel(data->img, i, j, color);
}

void	raycaster(t_data *data)
{
	int		i;
	int		j;
	double	dist;
	double	corrected_dist;
	double	wall_height;
	double	wall_top;
	double	wall_bot;

	i = 0;
	data->ray->rad_fov = FOV * (M_PI / 180);
	data->ray->angle = (data->player->angle - (data->ray->rad_fov * 0.5));
	while (i < WIDTH)
	{
		norm_angle(&data->ray->angle);
		dist = lazerizor(data, data->ray->angle) / 1.5;
		corrected_dist = dist * cos(data->ray->angle - data->player->angle);
		if (corrected_dist <= 0)
			corrected_dist = 0.1;
		wall_height = (TILE * HEIGHT) / corrected_dist;
		data->ray->rwall_height = wall_height;
		wall_top = (HEIGHT - wall_height) / 2;
		data->ray->rwall_top = wall_top;
		wall_bot = wall_top + wall_height;
		j = 0;
		while (j < HEIGHT) // axe x
		{
			if (j < wall_top)
				my_mlx_put_pixel(data->img, i, j, data->texture->ceiling.val);
			else if (j < wall_bot)
			{
				print_texture(data, i, j);
			}
			else
				my_mlx_put_pixel(data->img, i, j, data->texture->floor.val);
			j++;
		}
		data->ray->ray_dist = corrected_dist;
		data->ray->angle += data->ray->rad_fov / WIDTH;
		i++;
	}
}
