/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:55:53 by kapinarc          #+#    #+#             */
/*   Updated: 2025/10/24 12:06:00 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

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
	*hit_x = x;
	*hit_y = y;
	if (is_wall(data->map, x, y + pixel) == 2)
		return (INFINITY);
	return (sqrt(pow(x - data->player->px, 2) + pow(y - data->player->py, 2)));
}

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
	if (is_wall(data->map, x + pixel, y) == 2)
		return (INFINITY);
	return (sqrt(pow(y - data->player->py, 2) + pow(x - data->player->px, 2)));
}

double	lazerizor(t_data *data, double angle)
{
	double	x_hit_x;
	double	y_hit_y;
	double	y_hit_x;
	double	x_hit_y;

	data->ray->rx_dist = x_inter(data, angle, &x_hit_x, &x_hit_y);
	data->ray->ry_dist = y_inter(data, angle, &y_hit_x, &y_hit_y);
	if (data->ray->rx_dist == INFINITY && data->ray->ry_dist == INFINITY)
		return (INFINITY);
	if (data->ray->rx_dist <= data->ray->ry_dist)
	{
		data->ray->flag = 'x';
		data->ray->hit_x = x_hit_x;
		data->ray->hit_y = x_hit_y;
		return ((x_hit_x - data->player->px) * (cos(data->player->angle))
			+ (x_hit_y - data->player->py) * sin(data->player->angle));
	}
	data->ray->flag = 'y';
	data->ray->hit_x = y_hit_x;
	data->ray->hit_y = y_hit_y;
	return ((y_hit_x - data->player->px) * (cos(data->player->angle)) + (y_hit_y
			- data->player->py) * sin(data->player->angle));
}

static void	raycaster(t_data *data, double *wall_bot, double *wall_top)
{
	double	dist;
	double	wall_height;

	norm_angle(&data->ray->angle);
	dist = (double)(lazerizor(data, data->ray->angle));
	if (dist <= 0)
		dist = 1;
	wall_height = (TILE * HEIGHT) / dist;
	data->ray->rwall_height = wall_height;
	*wall_top = (HEIGHT - wall_height) / 2;
	data->ray->rwall_top = *wall_top;
	*wall_bot = *wall_top + wall_height;
}

void	raycast_loop(t_data *data)
{
	int		i;
	int		j;
	double	wall_top;
	double	wall_bot;

	i = -(WIDTH / 2) - 1;
	while (++i < WIDTH / 2)
	{
		data->ray->angle = data->player->angle + atan(data->ray->ratio * i);
		j = -1;
		raycaster(data, &wall_bot, &wall_top);
		while (++j < HEIGHT)
		{
			if (j < wall_top)
				my_mlx_put_pixel(data->img, i + WIDTH / 2, j,
					data->texture->ceiling.val);
			else if (j < wall_bot)
				print_texture(data, i + WIDTH / 2, j);
			else
				my_mlx_put_pixel(data->img, i + WIDTH / 2, j,
					data->texture->floor.val);
		}
	}
}
