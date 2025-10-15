#include "cub3d.h"

int	init_base(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->mlx = NULL;
	data->player = ft_calloc(1, sizeof(t_player));
	if (!data->player)
		return (1);
	if (init_player(data->player) != 0)
		return (1);
	return (0);
}
