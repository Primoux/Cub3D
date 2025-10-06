#include "cub3d.h"

static int	get_key_index(char *line, const char **keys)
{
	int	i;

	i = 0;
	while (keys[i] && ft_strncmp(line, keys[i], ft_strlen(keys[i])))
		++i;
	if (!keys[i])
		return (-1);
	return (i);
}

static int	assign_texture(t_map *m, int idx, char *trimed)
{
	char	**paths[6];

	paths[0] = &m->n_wall_path;
	paths[1] = &m->s_wall_path;
	paths[2] = &m->w_wall_path;
	paths[3] = &m->e_wall_path;
	paths[4] = &m->floor_color;
	paths[5] = &m->sky_color;
	if (*(paths[idx]) || !trimed)
	{
		free(trimed);
		return (-1);
	}
	*(paths[idx]) = trimed;
	return (0);
}

int	parse_for_textures(t_data *data, char *line)
{
	const char	*keys[] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", NULL};
	int			idx;
	char		*trimed;

	idx = get_key_index(line, keys);
	if (idx >= 0)
	{
		trimed = ft_strtrim(line + ft_strlen(keys[idx]), "\n");
		if (assign_texture(data->map, idx, trimed) == -1)
			return (-1);
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
