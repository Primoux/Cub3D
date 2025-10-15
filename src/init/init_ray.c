#include "cub3d.h"

int	init_ray(t_data *data)
{
	data->ray = ft_calloc(1, sizeof(t_ray));
	if (!data->ray)
		return (1);
	return (0);
}
