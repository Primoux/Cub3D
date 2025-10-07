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

void	get_x_step(t_data *data)
{
	float x;
	float y;

	x = data->ray->rx / TILE;
	y = data->ray->ry / TILE;

//	return (data.ray->x_step);
}

//rayon, trouver celui du millieu (angle 270) et les deux hypothenus
void	lazerizor(t_data *data)
{
	float x;
	float y;
	bool wall = false;

	x = data->player->px;
	y = data->player->py;
	
	while(y && !wall)
	{
		// printf("t dans le mur pelo la [x] = %f [%d] | [y] = %f [%d]\n", x, (int)x / TILE, y, (int)y /TILE);
		if (data->map->map[(int)y / TILE][(int)x / TILE] == '1')
		{
			wall = true;
		}
		usleep(20000);
		mlx_pixel_put(data->mlx, data->win, (int)x + (TILE >> 1) , (int)y, 0x00FF0000);
		// y = y - TILE;
		y--;
//		step_dad(x, y);
	}
}

//void	raycaster(t_data data)
//{
//	int i;
//	float rad_fov;
//
//	i = 0;
//	get_rad(data);
//	int first_ray = (data->player->angle - (FOV >> 1));
//	int last_ray = (data.player->angle + (FOV >> 1));
//	while (i < WIDTH)
//	{
////		rad_fov = last_ray - first_ray * (M_PI / 180); IL EST A JSP PAS PQ MAI PTT UTILE
//		lazerizor(data);
//		i++;
//	}
//}




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