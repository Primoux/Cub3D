#include "cub3d.h"
#include "init.h"

static void	init_base(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->mlx = NULL;
	data->win = NULL;
}

static int	init_map(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		ft_putstr_fd("init: failed to allocate map in the file : "__FILE__
			"\n",
			2);
		return (1);
	}
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
	data->img = malloc(sizeof(t_img));
	if (!data->img)
	{
		ft_putstr_fd("init: failed to allocate img in the file : "__FILE__
			"\n",
			2);
		return (1);
	}
	data->img->floor = NULL;
	data->img->wall = NULL;
	return (0);
}

int	init(t_data *data)
{
	init_base(data);
	if (init_map(data) != 0)
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
	return (0);
}
