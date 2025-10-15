#include "cub3d.h"

int	init_keys(t_data *data)
{
	data->key = ft_calloc(1, sizeof(t_key));
	if (!data->key)
		return (1);
	return (0);
}
