#include "cub3d.h"

void	free_all(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
	{
		if (data->map->file_name)
			free(data->map->file_name);
		free(data->map);
		data->map = NULL;
	}
	if (data->img)
	{
		free(data->img);
		data->img = NULL;
	}
}
