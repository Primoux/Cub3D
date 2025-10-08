#include "cub3d.h"
#include "mlx.h"
#include "mlx_management.h"
void charge_img(t_data *data)
{
	data->img->wall = mlx_xpm_file_to_image(data->mlx,
											"asset/textures/test_bloc2.xpm", &data->map->x, &data->map->y);
	data->img->floor = mlx_xpm_file_to_image(data->mlx, "asset/textures/test_bloc.xpm", &data->map->x, &data->map->y);
	data->img->perso_n = mlx_xpm_file_to_image(data->mlx, "asset/textures/test_perso.xpm", &data->map->x, &data->map->y);

}


int check_rad(t_data *data, double angle, double *x, double *y)
{
	(void)data;
//	data->ray->rad_fov = FOV * (M_PI / 180);
	printf("angle = %f\n", angle);
	if (angle >= 0 && angle < M_PI_2)
	{
		(*x) *= 1;
		(*y) *= 1;
	}
	if (angle >= M_PI_2 && angle < M_PI)
		(*x) *= -1;
	else if (angle >= 2 * M_PI && angle < 3 * M_PI_2)
	{
		(*x) *= -1;
		(*y) *= -1;
	}
	else if (angle >= M_PI_2 && angle < 2 * M_PI)
		(*y) *= -1;
	return (0);
}

bool is_wall(t_map *map, double x, double y)
{
	int	x_ray;
	int	y_ray;

	x_ray = floor(x / TILE);
	y_ray = floor(y / TILE);
	printf("x_ray = %d y_ray = %d\n", x_ray, y_ray);

	if (map->map[y_ray][x_ray] == '1')
	{
		printf("ara y a un mur = 3\n");
		return (true);
	}
	if (x_ray < 0 || y_ray < 0)
	{
		printf("1\n");
		return (true);
	}
//	if (!map->map[y_ray][x_ray])
//	{
//		printf("2\n");
//
//		return true;
//	}
//	if (y > map->y || x > map->x)
//	{
//		printf("2\n");
//		return (true);
//	}
	if (map->map[y_ray][x_ray] == '1')
	{
		printf("ara y a un mur = 3\n");
		return (true);
	}
	return (false);
}

double	y_inter(t_data *data, double angle)
{
	double x;
	double y;
	double x_step;
	double y_step;

	x_step = TILE;
	y_step = TILE * tan(angle);
	x = data->player->px / TILE * TILE;
	y = data->player->py + (x - data->player->px) * tan(angle);
	check_rad(data, angle, &x_step, &y_step);
	while (!is_wall(data->map, x, y))
	{
		printf("[x] = %f [%d] | [y] = %f [%d]\n", x, (int)x / TILE, y, (int)y /TILE);
		printf("[xstep] = %f [%d] | [ystep] = %f [%d]\n", x_step, (int)x / TILE, y_step, (int)y /TILE);
		mlx_pixel_put(data->mlx, data->win, (int)x  , (int)y, 0x00FF0000);
		y += y_step;
		x += x_step;
		usleep(500);
	}
	mlx_pixel_put(data->mlx, data->win, (int)x  , (int)y, 0x00FF0000);
	return (sqrt(pow(data->player->py - y, 2) + pow(data->player->px - x, 2)));
}

//double	x_inter(t_data *data, double angle)
//{
//	double x_step;
//	double y_step;
//
//	data->ray->rx = data->player->px;
//	data->ray->ry = data->player->py;
//
//	x_step = TILE / tan(angle);
//	y_step = TILE;
//
//	return (data->ray->x_step);
//}

void	lazerizor(t_data *data, double angle)
{
	double x;
	double y;
	bool wall;

	wall = false;
	x = data->player->px;
	y = data->player->py;

	y_inter(data,  angle);
//	while((y || x) && is_wall(data->map, x, y))
//	{
////		mlx_pixel_put(data->mlx, data->win, (int)x + (TILE >> 1) , (int)y, 0x00FF0000);
//		y += step_y;
////		y_inter(data, data->player->angle - (FOV >> 1));
////		x_inter(data, x);
//	}
}

void	norm_angle(double *angle)
{
	while(*angle < 0 || *angle  >= 2 * M_PI)
	{
		printf("ray charles angle = %f\n", *angle);
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
	printf("ray charles angle = %f\n", data->ray->angle);

	while (i < WIDTH)
	{
		norm_angle(&data->ray->angle);
		printf("pls ray angle = %f\n", data->ray->angle);
		printf("i = [%d]\n", i);
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