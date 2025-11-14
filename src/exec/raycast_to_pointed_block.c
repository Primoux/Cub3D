/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_to_pointed_block.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:30:42 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include <math.h>

static void	set_pointed_block(t_cube *cube, double x, double y)
{
	cube->destroy->pt_x = x / TILE;
	cube->destroy->pt_y = y / TILE;
}

static int	check_collision(t_cube *cube, int *map_x, int *map_y)
{
	if (*map_y < 0 || *map_y >= cube->map->y_max || *map_x < 0
		|| *map_x >= cube->map->x_max)
	{
		*map_x = 0;
		*map_y = 0;
		return (1);
	}
	if (cube->map->map[*map_y][*map_x] >= '1'
		&& cube->map->map[*map_y][*map_x] <= '6')
		return (1);
	return (0);
}

void	raycast_to_pointed_block(t_cube *cube)
{
	double	dist;
	double	x;
	double	y;
	int		map_x;
	int		map_y;

	dist = -1.0;
	x = cube->player->x + cos(cube->player->angle) * dist;
	y = cube->player->y + sin(cube->player->angle) * dist;
	while (++dist < RANGE_DESTROY * TILE)
	{
		map_x = (int)(x / TILE);
		map_y = (int)(y / TILE);
		if (check_collision(cube, &map_x, &map_y))
		{
			set_pointed_block(cube, x, y);
			return ;
		}
		x = cube->player->x + cos(cube->player->angle) * dist;
		y = cube->player->y + sin(cube->player->angle) * dist;
	}
	set_pointed_block(cube, x, y);
}
