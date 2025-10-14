#include "cub3d.h"
#include "mlx.h"
#include "mlx_management.h"

// void	charge_img(t_data *data) // proteger en cas de NULL
//{
//	data->texture->wall = mlx_xpm_file_to_image(data->mlx,
//			"asset/textures/test_bloc2.xpm", &data->map->x, &data->map->y);
//	data->texture->floor = mlx_xpm_file_to_image(data->mlx,
//			"asset/textures/test_bloc.xpm", &data->map->x, &data->map->y);
//	data->texture->perso_n = mlx_xpm_file_to_image(data->mlx,
//			"asset/textures/test_perso.xpm", &data->map->x, &data->map->y);
//}

void	add_image(t_data *data, t_img *img, int player_color, int wall_color)
{
	int	i;
	int	j;
	int	max_dim;
	int	scale;
	int	minimap_size;

	i = 0;
	j = 0;
	minimap_size = 400;
	if (data->map->x_max > data->map->y_max)
		max_dim = data->map->x_max;
	else
		max_dim = data->map->y_max;
	scale = minimap_size / max_dim;
	if (scale < 1)
		scale = 1;
	if (data->map->map[data->map->y][data->map->x] == '1')
	{
		while (i < scale)
		{
			j = 0;
			while (j < scale)
			{
				my_mlx_put_pixel(img, data->map->x * scale + i, data->map->y
					* scale + j, wall_color);
				j++;
			}
			i++;
		}
	}
	if (data->map->y == floor(data->player->py / TILE)
		&& data->map->x == floor(data->player->px / TILE))
	{
		i = 0;
		while (i < scale)
		{
			j = 0;
			while (j < scale)
			{
				my_mlx_put_pixel(img, data->map->x * scale + i, data->map->y
					* scale + j, player_color);
				j++;
			}
			i++;
		}
	}
}

void	imaginer(t_data *data)
{
	if (data->key->tab_key == true)
	{
		data->map->y = 0;
		while (data->map->map[data->map->y])
		{
			data->map->x = 0;
			while (data->map->map[data->map->y][data->map->x])
			{
				add_image(data, data->img, 0x00000, data->texture->floor.val);
				data->map->x++;
			}
			data->map->y++;
		}
	}
}
