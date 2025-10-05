#include "cub3d.h"

void	free_all(t_data *data)
{
	// free(data->map);
	free(data->map->file_name);
}
