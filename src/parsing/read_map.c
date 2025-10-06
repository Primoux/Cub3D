#include "parsing.h"

static int	parse_map(t_data *data, char *line)
{
	(void)data;
	(void)line;//a faire pour kaan
	return (0);
}

int	read_map(t_data *data)
{
	int	ret;

	while (data->map->line)
	{
		ret = parse_map(data, data->map->line);
		if (ret == 1)
			break ;
		else if (ret == -1)
		{
			free(data->map->line);
			return (1);
		}
		free(data->map->line);
		data->map->line = get_next_line(data->map->fd_map);
	}
	close(data->map->fd_map);
	return (0);
}
