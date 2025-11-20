/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:54 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/20 13:04:36 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

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
		return (print_error("str_free_to_join failed"
				, __FILE__, __LINE__, RETURN_1));
	*line = tmp;
	return (0);
}

int	read_map(t_cube *cube)
{
	char	*line;

	line = ft_strdup("");
	if (!line)
		return (print_error("ft_strdup failed", __FILE__, __LINE__, RETURN_1));
	while (skip_newline(&cube->map->line, cube->map->fd_map))
		;
	while (cube->map->line)
	{
		if (create_map(cube, &line) == 1)
		{
			free(line);
			free(cube->map->line);
			return (print_error("Empty line in map \
(you must have least one char)", __FILE__, __LINE__, RETURN_1));
		}
		free(cube->map->line);
		cube->map->line = get_next_line(cube->map->fd_map);
	}
	cube->map->line = ft_strdup(line);
	free(line);
	if (!cube->map->line)
		return (print_error("ft_strdup failed", __FILE__, __LINE__, RETURN_1));
	return (0);
}
