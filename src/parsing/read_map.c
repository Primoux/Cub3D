#include "parsing.h"

static int	create_map(t_data *data, char **line)
{
	char	*tmp;

	tmp = str_free_to_join(*line, data->map->line);
	if (!tmp)
		return (-1);
	*line = tmp;
	return (0);
}
// || data->map->line[0] == '\n'
int	read_map(t_data *data)
{
	int		ret;
	char	*line;

	line = ft_strdup("");
	if (!line)
		return (-1);
	while (data->map->line)
	{
		ret = create_map(data, &line);
		if (ret == 1)
			break ;
		else if (ret == -1)
		{
			free(line);
			free(data->map->line);
			return (1);
		}
		free(data->map->line);
		data->map->line = get_next_line(data->map->fd_map);

	}
	data->map->line = ft_strdup(line);
	free(line);
	return (0);
}
