#include "parsing.h"

int	read_and_fill_map_informations(t_data *data)
{
	if (read_params(data) == 1)
		return (1);
	if (!data->map->n_wall_path || !data->map->s_wall_path
		|| !data->map->w_wall_path || !data->map->e_wall_path
		|| !data->map->floor_color || !data->map->sky_color)
	{
		print_error_asset(data);
		return (1);
	}
	if (read_map(data) == 1)
		return (1);
	return (0);
}
