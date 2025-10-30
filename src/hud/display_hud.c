/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:20:56 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 14:40:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "destroy.h"
#include "mlx_management.h"
#include "hud.h"

void	display_hud(t_data *data, double current_time_s)
{
	draw_minimap(data);
	print_reticle(data);
	draw_infos(data, current_time_s);
	if (!(data->destroy->pt_y < 0 || data->destroy->pt_x < 0
			|| data->destroy->pt_x >= data->map->x_max
			|| data->destroy->pt_y >= data->map->y_max))
		destroy_bar(data,
			data->map->map[data->destroy->pt_y][data->destroy->pt_x]);
	stock_block(data);
}
