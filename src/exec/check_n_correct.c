#include "cub3d.h"
#include "mlx.h"
#include "mlx_management.h"

int	balance_inter(double angle, double *inter, double *step, int mode) // pixel
{
	if (mode == 0)
	{
		if (angle > M_PI && angle <= 2 * M_PI) // 180 to 360
		{
			*step *= -1;
			return (-1);
		}
		*inter += TILE;
	}
	else
	{
		if (angle > M_PI_2 && angle <= 3 * M_PI_2) // entre 90 et 270
		{
			*step *= -1;
			return (-1); // a gauche
		}
		*inter += TILE;
	}
	(void)*inter;
	return (1); // a droite
}

int	ray_dir(double angle, int mode)
{
	if (mode == 0)
	{
		if (angle > M_PI) // 180 to 360 vers le haut
		{
			return (0);
		}
	}
	else
	{
		if (angle > M_PI_2 && angle <= 3 * M_PI_2) // 90 to 180 vers le bas
		{
			return (0); // angle 'y' a gauche
		}
	}
	return (1); // angle 'y' a droite et x vers bas
}

void	norm_angle(double *angle)
{
	while (*angle < 0 || *angle >= 2 * M_PI)
	{
		//		printf("ray charles angle = %f\n", *angle);
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
	if (x_ray < 0 || y_ray < 0 || x_ray >= HEIGHT / TILE || y_ray >= WIDTH
		/ TILE)
	{
		return (true);
	}
	if (y_ray >= map->y_max)
		return (true);
	len = ft_strlen(map->map[y_ray]);
	if (x_ray >= len)
		return (true);
	if (map && map->map[y_ray][x_ray] != '0' && map && map->map[y_ray][x_ray] != 'N' &&
		map && map->map[y_ray][x_ray] != 'S' && map && map->map[y_ray][x_ray] != 'E' &&
		map && map->map[y_ray][x_ray] != 'W')
		return (true);
	return (false);
}
