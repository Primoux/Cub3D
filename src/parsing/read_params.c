/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:53:01 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/23 19:17:51 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_key_index(char **line, const char **keys)
{
	int	i;

	i = 0;
	while (*line && ft_is_white_space(**line))
		(*line)++;
	while (keys[i] && ft_strncmp(*line, keys[i], ft_strlen(keys[i])))
		++i;
	if (!keys[i])
		return (-1);
	return (i);
}

static int	assign_texture(t_map *m, int idx, char *trimed)
{
	char	**params[6];
	int		i;

	i = 0;
	params[0] = &m->n_wall_path;
	params[1] = &m->s_wall_path;
	params[2] = &m->w_wall_path;
	params[3] = &m->e_wall_path;
	params[4] = &m->floor_color;
	params[5] = &m->ceiling_color;
	if (*(params[idx]) && *(*(params[idx])))
	{
		free(trimed);
		return (-1);
	}
	if (!ft_is_white_space(trimed[0]))
		return (1);
	while (trimed[i] && ft_is_white_space(trimed[i]))
		i++;
	*(params[idx]) = ft_strdup(&trimed[i]);
	free(trimed);
	if (!*(params[idx]))
		return (-1);
	return (0);
}

int	parse_for_textures(t_data *data, char *line)
{
	const char	*keys[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int			idx;
	char		*trimed;

	idx = get_key_index(&line, keys);
	if (idx >= 0)
	{
		trimed = ft_strtrim(line + ft_strlen(keys[idx]), "\n");
		if (!trimed)
			return (-1);
		if (assign_texture(data->map, idx, trimed) == -1)
		{
			ft_dprintf(2, "Error: duplicated params for key '%s'\n", keys[idx]);
			return (1);
		}
	}
	if ((line[0] == '1' || line[0] == ' ' || line[0] == '\t')
		|| (!ft_strnstr(line, "NO", 3) && !ft_strnstr(line, "SO", 3)
			&& !ft_strnstr(line, "WE", 3) && !ft_strnstr(line, "EA", 3)
			&& !ft_strnstr(line, "F", 2) && !ft_strnstr(line, "C", 2)))
		return (1);
	return (0);
}

int	read_params(t_data *data)
{
	int	ret;

	data->map->line = get_next_line(data->map->fd_map);
	while (data->map->line)
	{
		ret = parse_for_textures(data, data->map->line);
		if (ret == -1)
		{
			free(data->map->line);
			return (0);
		}
		else if (ret == 1)
			break ;
		free(data->map->line);
		data->map->line = get_next_line(data->map->fd_map);
	}
	return (0);
}
