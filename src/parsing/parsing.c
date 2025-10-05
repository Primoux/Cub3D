#include "parsing.h"
#include <stdlib.h>
#include <unistd.h>

int	parsing(t_data *data, char *argv)
{
	if (check_name_and_access(data, argv) == 1)
		return (1);
	data->map->file_name = ft_strdup(argv);
	if (!data->map->file_name)
		return (1);
	close(data->map->fd_map);
	return (EXIT_SUCCESS);
}
