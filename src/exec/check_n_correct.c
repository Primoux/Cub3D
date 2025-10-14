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
	(void)*inter;
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

bool	is_wall(t_map *map, double x, double y)
{
	int	x_ray;
	int	y_ray;
	int	len;

	x_ray = floor(x / TILE);
	y_ray = floor(y / TILE);
	if (x_ray < 0 || y_ray < 0)
	{
		return (true);
	}
	if (y_ray >= map->y_max)
		return (true);
	len = ft_strlen(map->map[y_ray]);
	if (x_ray >= len)
		return (true);
	if (map && map->map[y_ray][x_ray] != '0' && map->map[y_ray][x_ray] != 'N'
		&& map->map[y_ray][x_ray] != 'S' && map->map[y_ray][x_ray] != 'E'
		&& map->map[y_ray][x_ray] != 'W')
		return (true);
	return (false);
}
