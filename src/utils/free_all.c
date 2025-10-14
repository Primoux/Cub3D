#include "cub3d.h"

void	free_all(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
	{
		safe_close(&data->map->fd_map);
		free(data->map->file_name);
		free(data->map->n_wall_path);
		free(data->map->s_wall_path);
		free(data->map->w_wall_path);
		free(data->map->e_wall_path);
		free(data->map->floor_color);
		free(data->map->ceiling_color);
		free(data->player);
		if (data->map->map)
			free_tab_return_null(data->map->map);
		free(data->map);
	}
	if (data->ray)
		free(data->ray);
	if (data->mlx)
		free(data->mlx);
	if (data->texture)
		free(data->texture);
}
