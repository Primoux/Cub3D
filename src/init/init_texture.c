#include "cub3d.h"

int	init_texture(t_data *data)
{
	data->texture = ft_calloc(1, sizeof(t_texture));
	if (!data->texture)
		return (1);
	return (0);
}
