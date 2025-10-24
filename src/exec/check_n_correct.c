/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_correct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:05:52 by kapinarc          #+#    #+#             */
/*   Updated: 2025/10/24 07:35:26 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include "mlx_management.h"

int	balance_inter(double angle, double *inter, double *step, int mode)
{
	if (mode == 0)
	{
		if (angle > M_PI && angle <= 2 * M_PI)
		{
			*step *= -1;
			return (-1);
		}
		*inter += TILE;
	}
	else
	{
		if (angle > M_PI_2 && angle <= 3 * M_PI_2)
		{
			*step *= -1;
			return (-1);
		}
		*inter += TILE;
	}
	return (1);
}

int	ray_dir(double angle, int mode)
{
	if (mode == 0)
	{
		if (angle > M_PI)
		{
			return (0);
		}
	}
	else
	{
		if (angle > M_PI_2 && angle <= 3 * M_PI_2)
		{
			return (0);
		}
	}
	return (1);
}

void	norm_angle(double *angle)
{
	while (*angle < 0 || *angle >= 2 * M_PI)
	{
		if (*angle < 0)
			*angle += 2 * M_PI;
		if (*angle >= 2 * M_PI)
			*angle -= 2 * M_PI;
	}
}

int	is_wall(t_map *map, double x, double y)
{
	int	x_ray;
	int	y_ray;
	int	len;

	x_ray = floor(x / TILE);
	y_ray = floor(y / TILE);
	if (x_ray < 0 || y_ray < 0)
		return (2);
	if (y_ray > map->y_max)
		return (2);
	len = ft_strlen(map->map[y_ray]) + 1;
	if (x_ray > len)
		return (2);
	if (map && map->map[y_ray][x_ray] != 'O' && map->map[y_ray][x_ray] != 'N'
		&& map->map[y_ray][x_ray] != 'S' && map->map[y_ray][x_ray] != 'E'
		&& map->map[y_ray][x_ray] != 'W')
		return (1);
	return (0);
}
