#include "cub3d.h"
#include "mlx.h"
#include "mlx_management.h"


int	balance_inter(double angle, double *inter, double *step, int mode)
{
	if (mode == 0)
	{
		if (angle > M_PI && angle <= 2 * M_PI) //180 to 360
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
			*step  *= -1;
			return (-1); // a gauche
		}
		*inter += TILE;
	}
	return (1); //a droite
}

int	ray_dir(double angle, int mode)
{
	if (mode == 0)
	{
		if (angle > M_PI) //180 to 360 vers le haut
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

	return (1); //angle 'y' a droite et x vers bas
}

void	norm_angle(double *angle)
{
	while(*angle < 0 || *angle  >= 2 * M_PI)
	{
//		printf("ray charles angle = %f\n", *angle);
		if (*angle < 0)
			*angle += 2 * M_PI;
		if (*angle >= 2 * M_PI)
			*angle -= 2 * M_PI;
	}
}

bool is_wall(t_map *map, double x, double y)
{
	int	x_ray;
	int	y_ray;

	x_ray = floor(x / TILE);
	y_ray = floor(y / TILE);
	printf("(fonction is_wall) x_ray = %d y_ray = %d\n", x_ray, y_ray);
	printf("(fonction is_wall) x = %f y = %f\n", x, y);

	if (x_ray < 0 || y_ray < 0)
	{
		printf("1\n");
		return (true);
	}
//	if (!map->map[y_ray][x_ray])
//	{
//		printf("2\n");
//		return (true);
//	}
	if (map && map->map[y_ray][x_ray] == '1')
	{
		printf("ara y a un mur  3\n");
		return (true);
	}
	return (false);
}
