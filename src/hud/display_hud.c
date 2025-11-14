/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:20:56 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "destroy.h"
#include "mlx_management.h"
#include "hud.h"

void	display_hud(t_cube *cube, double current_time_s)
{
	draw_minimap(cube);
	print_reticle(cube);
	draw_infos(cube, current_time_s);
	if (!(cube->destroy->pt_y < 0 || cube->destroy->pt_x < 0
			|| cube->destroy->pt_x >= cube->map->x_max
			|| cube->destroy->pt_y >= cube->map->y_max))
		destroy_bar(cube,
			cube->map->map[cube->destroy->pt_y][cube->destroy->pt_x]);
	stock_block(cube);
}
