#include "cub3d.h"
#include "init.h"

static int	init_base(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->mlx = NULL;
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		return (1);
	data->player->px = 0;
	data->player->py = 0;
	return (0);
}

static int	init_map(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (1);
	data->map->file_name = NULL;
	data->map->map = NULL;
	data->map->n_wall_path = NULL;
	data->map->s_wall_path = NULL;
	data->map->e_wall_path = NULL;
	data->map->w_wall_path = NULL;
	data->map->floor_color = NULL;
	data->map->sky_color = NULL;
	return (0);
}

static int	init_img(t_data *data)
{
	data->texture = malloc(sizeof(t_texture));
	if (!data->texture)
		return (1);
	data->texture->floor = NULL;
	data->texture->wall = NULL;
	return (0);
}

static int	init_ray(t_data *data)
{
	data->ray = malloc(sizeof(t_ray)); // cacaboudin
	if (!data->ray)
		return (1);
	return (0);
}

int	init(t_data *data)
{
	if ((init_base(data) != 0) || (init_map(data) != 0))
		return (1);
	if (init_img(data) != 0)
	{
		if (data->map)
		{
			if (data->map->file_name)
				free(data->map->file_name);
			free(data->map);
			data->map = NULL;
		}
		return (1);
	}
	if (init_ray(data) == 1)
		return (1);
	data->img = ft_calloc(1, sizeof(t_img)); // pu la merde
	data->key = ft_calloc(1, sizeof(t_key));// pu la merde
	return (0);
}
