/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:55:53 by kapinarc          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include "raycast.h"
#include "utils.h"
#include <math.h>

double	x_inter(t_cube *cube, double angle, double *hit_x, double *hit_y)
{
	double	x_step;
	double	y_step;
	double	x;
	double	y;
	int		pixel;

	y_step = TILE;
	x_step = TILE / tan(angle);
	y = floor(cube->player->y / TILE) * TILE;
	pixel = balance_inter(angle, &y, &y_step, 0);
	x = cube->player->x + (y - cube->player->y) / tan(angle);
	if ((ray_dir(angle, 1) && x_step < 0) || (!ray_dir(angle, 1) && x_step > 0))
		x_step *= -1;
	while (!is_wall(cube->map, x, y + pixel))
	{
		x += x_step;
		y += y_step;
	}
	*hit_x = x;
	*hit_y = y;
	if (is_wall(cube->map, x, y + pixel) == 2)
		return (INFINITY);
	return (sqrt(pow(x - cube->player->x, 2) + pow(y - cube->player->y, 2)));
}

double	y_inter(t_cube *cube, double angle, double *hit_x, double *hit_y)
{
	double	x;
	double	y;
	double	x_step;
	double	y_step;
	int		pixel;

	x_step = TILE;
	y_step = TILE * tan(angle);
	x = floor(cube->player->x / TILE) * TILE;
	pixel = balance_inter(angle, &x, &x_step, 1);
	y = cube->player->y + (x - cube->player->x) * tan(angle);
	if ((ray_dir(angle, 0) && y_step < 0) || (!ray_dir(angle, 0) && y_step > 0))
		y_step *= -1;
	while (!is_wall(cube->map, x + pixel, y))
	{
		y += y_step;
		x += x_step;
	}
	*hit_x = x;
	*hit_y = y;
	if (is_wall(cube->map, x + pixel, y) == 2)
		return (INFINITY);
	return (sqrt(pow(y - cube->player->y, 2) + pow(x - cube->player->x, 2)));
}

double	lazerizor(t_cube *cube, double angle)
{
	double	x_hit_x;
	double	y_hit_y;
	double	y_hit_x;
	double	x_hit_y;

	cube->ray->rx_dist = x_inter(cube, angle, &x_hit_x, &x_hit_y);
	cube->ray->ry_dist = y_inter(cube, angle, &y_hit_x, &y_hit_y);
	if (cube->ray->rx_dist == INFINITY && cube->ray->ry_dist == INFINITY)
		return (INFINITY);
	if (cube->ray->rx_dist <= cube->ray->ry_dist)
	{
		cube->ray->flag = 'x';
		cube->ray->hit_x = x_hit_x;
		cube->ray->hit_y = x_hit_y;
		return ((x_hit_x - cube->player->x) * (cos(cube->player->angle))
			+ (x_hit_y - cube->player->y) * sin(cube->player->angle));
	}
	cube->ray->flag = 'y';
	cube->ray->hit_x = y_hit_x;
	cube->ray->hit_y = y_hit_y;
	return ((y_hit_x - cube->player->x) * (cos(cube->player->angle))
		+ (y_hit_y - cube->player->y) * sin(cube->player->angle));
}

static void	raycaster(t_cube *cube, double *wall_bot, double *wall_top)
{
	double	dist;
	double	wall_height;
	double	ratio;

	norm_angle(&cube->ray->angle);
	ratio = tanf(cube->ray->rad_fov / 2);
	dist = (double)(lazerizor(cube, cube->ray->angle));
	if (dist <= 0)
		dist = 1;
	wall_height = ((TILE * WIDTH * 0.5) / dist) / ratio;
	cube->ray->rwall_height = wall_height;
	*wall_top = (HEIGHT - wall_height) / 2;
	cube->ray->rwall_top = *wall_top;
	*wall_bot = *wall_top + wall_height;
}

void	raycast_loop(t_cube *cube)
{
	int		i;
	int		j;
	double	wall_top;
	double	wall_bot;

	i = -(WIDTH / 2) - 1;
	while (++i < WIDTH / 2)
	{
		cube->ray->angle = cube->player->angle + atan(cube->ray->ratio * i);
		j = -1;
		raycaster(cube, &wall_bot, &wall_top);
		while (++j < HEIGHT)
		{
			if (j < wall_top)
				my_mlx_put_pixel(cube->img, i + WIDTH / 2, j,
					cube->texture->ceiling.val);
			else if (j < wall_bot)
				print_texture(cube, i + WIDTH / 2, j);
			else
				my_mlx_put_pixel(cube->img, i + WIDTH / 2, j,
					cube->texture->floor.val);
		}
	}
}
