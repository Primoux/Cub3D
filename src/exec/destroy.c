/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:10:05 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

void	reset_block(t_cube *cube)
{
	if (cube->destroy->destroying == true && cube->destroy->begin_destroy
		!= -1.0 && cube->destroy->x >= 0 && cube->destroy->y >= 0)
	{
		cube->map->map[cube->destroy->y][cube->destroy->x]
			= cube->destroy->saved_block;
	}
	cube->destroy->begin_destroy = -1.0;
	cube->destroy->x = -1;
	cube->destroy->y = -1;
	cube->destroy->stage = 0;
	cube->destroy->destroying = false;
}

void	reset_saved_block(t_cube *cube)
{
	if (cube->destroy->x >= 0 && cube->destroy->y >= 0
		&& cube->destroy->begin_destroy != -1.0)
		cube->map->map[cube->destroy->y][cube->destroy->x]
			= cube->destroy->saved_block;
	cube->destroy->begin_destroy = -1.0;
	cube->destroy->x = -1;
	cube->destroy->y = -1;
	cube->destroy->stage = 0;
}

void	begin_destroy(t_cube *cube, int tile_x, int tile_y,
		double current_time_s)
{
	cube->destroy->saved_block = cube->map->map[tile_y][tile_x];
	cube->map->map[tile_y][tile_x] = '5';
	cube->destroy->x = tile_x;
	cube->destroy->y = tile_y;
	cube->destroy->stage = 0;
	cube->destroy->begin_destroy = current_time_s;
	cube->destroy->destroying = true;
}

void	destroy(t_cube *cube, int tile_x, int tile_y)
{
	if (cube->destroy->stage++ < 4)
		cube->map->map[tile_y][tile_x]--;
	else
	{
		cube->map->map[tile_y][tile_x] = 'O';
		cube->destroy->begin_destroy = -1.0;
		cube->destroy->x = -1;
		cube->destroy->y = -1;
		cube->destroy->stage = 0;
		cube->destroy->destroying = false;
		cube->player->blocks++;
	}
}

void	destroy_block(t_cube *cube, int tile_x, int tile_y,
		double current_time_s)
{
	if (cube->key->mouse_1 == false)
	{
		reset_block(cube);
		return ;
	}
	if (cube->destroy->x != tile_x || cube->destroy->y != tile_y)
		reset_saved_block(cube);
	if (cube->map->map[tile_y][tile_x] < '1'
		|| cube->map->map[tile_y][tile_x] > '5')
		return ;
	if (cube->destroy->begin_destroy == -1.0)
	{
		begin_destroy(cube, tile_x, tile_y, current_time_s);
		return ;
	}
	if (current_time_s - cube->destroy->begin_destroy >= (TT_DESTROY / 4)
		* (cube->destroy->stage + 1))
		destroy(cube, tile_x, tile_y);
	cube->destroy->destroying = true;
}
