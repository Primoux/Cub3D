#include "cub3d.h"
#include "mlx.h"
#include "mlx_management.h"

void	charge_img(t_data *data) // proteger en cas de NULL
{
	data->texture->wall = mlx_xpm_file_to_image(data->mlx,
			"asset/textures/test_bloc2.xpm", &data->map->x, &data->map->y);
	data->texture->floor = mlx_xpm_file_to_image(data->mlx,
			"asset/textures/test_bloc.xpm", &data->map->x, &data->map->y);
	data->texture->perso_n = mlx_xpm_file_to_image(data->mlx,
			"asset/textures/test_perso.xpm", &data->map->x, &data->map->y);
}

void	add_image(t_data *data)
{
	if (data->map->map[data->map->y][data->map->x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->texture->wall,
			data->map->x * TILE, data->map->y * TILE);
	if (data->map->map[data->map->y][data->map->x] == '0'
		|| data->map->map[data->map->y][data->map->x] == 'N'
		|| data->map->map[data->map->y][data->map->x] == 'S'
		|| data->map->map[data->map->y][data->map->x] == 'E'
		|| data->map->map[data->map->y][data->map->x] == 'W')
		mlx_put_image_to_window(data->mlx, data->win, data->texture->floor,
			data->map->x * TILE, data->map->y * TILE);
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
