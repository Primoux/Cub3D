/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:54 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	skip_newline(char **line, int fd)
{
	while (ft_str_is_only_space(*line) == 0)
	{
		free(*line);
		*line = get_next_line(fd);
		return (1);
	}
	return (0);
}

static int	create_map(t_cube *cube, char **line)
{
	char	*tmp;

	if (skip_newline(&cube->map->line, cube->map->fd_map))
		return (1);
	tmp = str_free_to_join(*line, cube->map->line);
	if (!tmp)
		return (1);
	*line = tmp;
	return (0);
}

int	read_map(t_cube *cube)
{
	char	*line;

	line = ft_strdup("");
	if (!line)
		return (1);
	while (skip_newline(&cube->map->line, cube->map->fd_map))
		;
	cube->map->y_max = 0;
	while (cube->map->line)
	{
		if (create_map(cube, &line) == 1)
		{
			free(line);
			free(cube->map->line);
			return (1);
		}
		free(cube->map->line);
		cube->map->line = get_next_line(cube->map->fd_map);
		cube->map->y_max++;
	}
	cube->map->line = ft_strdup(line);
	free(line);
	return (0);
}
