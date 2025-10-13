#include "cub3d.h"
#include "mlx.h"
#include "mlx_management.h"
void charge_img(t_data *data) // proteger en cas de NULL
{
	data->img->wall = mlx_xpm_file_to_image(data->mlx,
											"asset/textures/test_bloc2.xpm", &data->map->x, &data->map->y);
	data->img->floor = mlx_xpm_file_to_image(data->mlx, "asset/textures/test_bloc.xpm", &data->map->x, &data->map->y);
	data->img->perso_n = mlx_xpm_file_to_image(data->mlx, "asset/textures/test_perso.xpm", &data->map->x, &data->map->y);

}

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
	if (!map->map[y_ray][x_ray])
	{
		printf("2\n");
		return true;
	}
	if (map && map->map[y_ray][x_ray] == '1')
	{
		printf("ara y a un mur = 3\n");
		return (true);
	}
//	if (y > map->y || x > map->x)
//	{
//		printf("2\n");
//		return (true);
//	}
	return (false);
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

// fonction y_inter
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
	printf("(fonction lazerizor) %f\n", angle * 180 / M_PI);

	y_inter(data,  angle);
	x_inter(data,  angle);

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

void	add_image(t_data *data)
{
	if (data->map->map[data->map->y][data->map->x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img->wall, data->map->x * TILE , data->map->y * TILE);
	if (data->map->map[data->map->y][data->map->x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img->floor, data->map->x * TILE , data->map->y * TILE);
	if (data->map->map[data->map->y][data->map->x] == 'N')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->floor, data->map->x * TILE  , data->map->y * TILE);
		mlx_put_image_to_window(data->mlx, data->win, data->img->perso_n, data->map->x * TILE + (TILE >> 1) - 35 , data->map->y * TILE + (TILE >> 1) - 35); // lolilol
	}
//	if (data->map->map[data.map->y][data.map->x] == 'S')
//	{
//		mlx_put_image_to_window(data.mlx, data.win, data.img->floor, data.map->x * TILE , data.map->y * TILE);
//		mlx_put_image_to_window(data.mlx, data.win, data.img->perso, data.map->x * TILE , data.map->y * TILE);
//	}
//	if (data.map->map[data.map->y][data.map->x] == 'E')
//	{
//		mlx_put_image_to_window(data.mlx, data.win, data.img->floor, data.map->x * TILE , data.map->y * TILE);
//		mlx_put_image_to_window(data.mlx, data.win, data.img->perso, data.map->x * TILE , data.map->y * TILE);
//	}
//	if (data.map->map[data.map->y][data.map->x] == 'W')
//	{
//		mlx_put_image_to_window(data.mlx, data.win, data.img->floor, data.map->x * TILE , data.map->y * TILE);
//		mlx_put_image_to_window(data.mlx, data.win, data.img->perso, data.map->x * TILE , data.map->y * TILE);
//	}
}

void	imaginer(t_data *data)
{
	charge_img(data);
	data->map->y = 0;
	while (data->map->map[data->map->y])
	{
		data->map->x = 0;
		while (data->map->map[data->map->y][data->map->x])
		{
			add_image(data);
			data->map->x++;
		}
		data->map->y++;
	}
}