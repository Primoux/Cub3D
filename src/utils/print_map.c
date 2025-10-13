#include "cub3d.h"

void	print_map_and_params(t_data *data)
{
	int	i;

	ft_printf("%s\n", data->map->n_wall_path);
	ft_printf("%s\n", data->map->s_wall_path);
	ft_printf("%s\n", data->map->w_wall_path);
	ft_printf("%s\n", data->map->e_wall_path);
	ft_printf("%s\n", data->map->sky_color);
	ft_printf("%s\n", data->map->floor_color);
	i = 0;
	while (data->map->map[i])
	{
		ft_printf("%s\n", data->map->map[i]);
		i++;
	}
	ft_printf("y_max = %d\nx_max = %d\n", data->map->y_max, data->map->x_max);
}
