/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_fill_map_informations.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:53:04 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/20 13:03:20 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

static int	ensure_textures(t_cube *cube)
{
	if (!cube->map->n_wall_path || !cube->map->s_wall_path
		|| !cube->map->w_wall_path || !cube->map->e_wall_path
		|| !cube->map->floor_color || !cube->map->ceiling_color)
	{
		free(cube->map->line);
		return (print_error("Invalid map\nMissing/Duplicate texture/color",
				__FILE__, __LINE__, RETURN_1));
	}
	return (0);
}

int	read_and_fill_map_informations(t_cube *cube)
{
	if (read_params(cube) == 1 || ensure_textures(cube) == 1)
		return (1);
	if (!cube->map->line)
		return (print_error("No map in file check file", __FILE__, __LINE__,
				RETURN_1));
	if (read_map(cube) == 1)
		return (1);
	cube->map->map = ft_split(cube->map->line, '\n');
	free(cube->map->line);
	if (!cube->map->map)
		return (print_error("ft_split failed", __FILE__, __LINE__, RETURN_1));
	return (0);
}
