#include "cub3d.h"

int	init_img(t_data *data)
{
	data->img = ft_calloc(1, sizeof(t_img));
	if (!data->img)
		return (1);
	return (0);
}
