#include "cub3d.h"

int	parse_for_textures(t_data *data, char *line)
{
	const char	*keys[] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", NULL};
	char		**paths[] = {&data->map->n_wall_path, &data->map->s_wall_path,
				&data->map->w_wall_path, &data->map->e_wall_path,
				&data->map->floor_color, &data->map->sky_color, NULL};
	int			i;
	char		*trimed_line;

	i = -1;
	while (keys[++i])
	{
		if (ft_strncmp(line, keys[i], ft_strlen(keys[i])) == 0)
		{
			trimed_line = ft_strtrim(line + ft_strlen(keys[i]), "\n");
			if (*(paths[i]) || !trimed_line)
			{
				if (trimed_line)
					free(trimed_line);
				return (-1);
			}
			*(paths[i]) = trimed_line;
			break ;
		}
	}
	if (line[0] == '1' || line[0] == ' ' || line[0] == '\t')
		return (1);
	return (0);
}

int	read_params(t_data *data)
{
	int	ret;

	data->map->line = NULL;
	data->map->line = get_next_line(data->map->fd_map);
	while (data->map->line)
	{
		ret = parse_for_textures(data, data->map->line);
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
	return (0);
}
