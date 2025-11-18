/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_fill_map_informations.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:53:04 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/18 13:06:20 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

static int	ensure_textures(t_cube *cube)
{
	if (!cube || !cube->map)
		return (1);
	if (!cube->map->n_wall_path || !cube->map->s_wall_path
		|| !cube->map->w_wall_path || !cube->map->e_wall_path
		|| !cube->map->floor_color || !cube->map->ceiling_color)
	{
		free(cube->map->line);
		ft_dprintf(2, "Error\nInvalid map\n");
		return (1);
	}
	return (0);
}

int	read_and_fill_map_informations(t_cube *cube)
{
	if (!cube || !cube->map)
		return (1);
	if (read_params(cube) == 1)
		return (1);
	if (ensure_textures(cube) == 1)
		return (1);
	if (!cube->map->line)
	{
		ft_dprintf(2, "Error\nNo map in file\n");
		return (1);
	}
	if (read_map(cube) == 1)
	{
		ft_dprintf(2, "Error\nread_map returned an error\n");
		return (1);
	}
	cube->map->map = ft_split(cube->map->line, '\n');
	free(cube->map->line);
	if (!cube->map->map)
	{
		ft_dprintf(2, "Error\nft_split returned an error\n");
		return (1);
	}
	return (0);
}
