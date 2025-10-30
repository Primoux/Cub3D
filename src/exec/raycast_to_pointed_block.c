/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_to_pointed_block.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:30:42 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/29 17:31:44 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

static void	set_pointed_block(t_data *data, double x, double y)
{
	data->destroy->pt_x = x / TILE;
	data->destroy->pt_y = y / TILE;
}

static int	check_collision(t_data *data, int map_x, int map_y)
{
	if (map_y < 0 || map_y >= data->map->y_max || map_x < 0
		|| map_x >= data->map->x_max)
		return (1);
	if (data->map->map[map_y][map_x] >= '1'
		&& data->map->map[map_y][map_x] <= '6')
		return (1);
	return (0);
}

void	raycast_to_pointed_block(t_data *data)
{
	double	dist;
	double	x;
	double	y;
	int		map_x;
	int		map_y;

	dist = -1.0;
	while (++dist < RANGE_DESTROY * TILE)
	{
		x = data->player->x + cos(data->player->angle) * dist;
		y = data->player->y + sin(data->player->angle) * dist;
		map_x = (int)(x / TILE);
		map_y = (int)(y / TILE);
		if (check_collision(data, map_x, map_y))
		{
			set_pointed_block(data, x, y);
			return ;
		}
	}
	set_pointed_block(data, x, y);
}
