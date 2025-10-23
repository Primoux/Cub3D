/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:27:37 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/23 19:45:04 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	if (map->fd_map >= 0)
		safe_close(&map->fd_map);
	free(map->file_name);
	free(map->n_wall_path);
	free(map->s_wall_path);
	free(map->w_wall_path);
	free(map->e_wall_path);
	free(map->floor_color);
	free(map->ceiling_color);
	if (map->map)
		free_tab_return_null(map->map);
	free(map);
}
