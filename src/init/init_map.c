#include "cub3d.h"

int	init_map(t_data *data)
{
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
		return (1);
	return (0);
}
