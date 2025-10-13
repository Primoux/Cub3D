#include "parsing.h"
#include <stdlib.h>
#include <unistd.h>

int	parsing(t_data *data, char *argv)
{
	int	i;
	int	len;

	if (check_name_and_access(data, argv) == 1)
		return (1);
	data->map->file_name = ft_strdup(argv);
	if (!data->map->file_name)
		return (1);
	if (read_and_fill_map_informations(data) == 1 || check_map_validity(data,
			data->map->map) == 1)
		return (1);
	i = 0;
	while (i < data->map->y_max)
	{
		len = ft_strlen((data->map->map[i]));
		if (len > data->map->x_max)
			data->map->x_max = len - 1;
		i++;
	}
	print_map_and_params(data);
	return (EXIT_SUCCESS);
}
