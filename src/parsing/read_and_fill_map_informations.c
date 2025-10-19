#include "parsing.h"

static int	ensure_textures(t_data *data)
{
	if (!data || !data->map)
		return (1);
	if (!data->map->n_wall_path || !data->map->s_wall_path
		|| !data->map->w_wall_path || !data->map->e_wall_path
		|| !data->map->floor_color || !data->map->ceiling_color)
	{
		print_error_asset(data);
		return (1);
	}
	return (0);
}

int	read_and_fill_map_informations(t_data *data)
{
	if (!data || !data->map)
		return (1);
	if (read_params(data) == 1)
		return (1);
	if (ensure_textures(data) == 1)
		return (1);
	if (!data->map->line)
	{
		ft_dprintf(2, "Error: empty map data in %s\n", __FILE__);
		return (1);
	}
	if (read_map(data) == 1)
	{
		ft_dprintf(2, "Error: reading map in %s\n", __FILE__);
		return (1);
	}
	data->map->map = ft_split(data->map->line, '\n');
	free(data->map->line);
	if (!data->map->map)
	{
		ft_dprintf(2, "Error: ft_split failed in %s\n", __FILE__);
		return (1);
	}
	return (0);
}
