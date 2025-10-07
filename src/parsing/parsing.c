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
	if (read_and_fill_map_informations(data) == 1 || check_map_validity(data,
			data->map->map) == 1)
		return (1);
	print_map_and_params(data);
	return (EXIT_SUCCESS);
}
