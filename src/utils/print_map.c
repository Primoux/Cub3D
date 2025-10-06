#include "cub3d.h"

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
	{
		printf("[%d] %s\n", i, data->map->map[i]);
		i++;
	}
}
