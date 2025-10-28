/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hud.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:04:53 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/27 19:37:20 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

void	display_hud(t_data *data, double current_time_s)
{
	draw_minimap(data);
	print_reticle(data);
	draw_fps(data, current_time_s);
	if (!(data->player->pointed_y <= 0 || data->player->pointed_x <= 0
			|| data->player->pointed_x >= data->map->x_max
			|| data->player->pointed_y >= data->map->y_max))
		destroy_bar(data,
			data->map->map[data->player->pointed_y][data->player->pointed_x]);
	stock_block(data);
}