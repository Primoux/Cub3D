#include "cub3d.h"

void	print_map_and_params(t_data *data)
{
	int	i;

	printf("%s\n", data->map->n_wall_path);
	printf("%s\n", data->map->s_wall_path);
	printf("%s\n", data->map->w_wall_path);
	printf("%s\n", data->map->e_wall_path);
	printf("%s\n", data->map->sky_color);
	printf("%s\n", data->map->floor_color);
	i = 0;
	while (data->map->map[i])
	{
		printf("%s\n", data->map->map[i]);
		i++;
	}
}
