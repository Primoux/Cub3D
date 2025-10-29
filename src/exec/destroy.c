/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:10:05 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/29 15:16:01 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

void	reset_block(t_data *data)
{
	if (data->destroy->destroying == true && data->destroy->begin_destroy !=
		-1.0 && data->destroy->destroy_x >= 0
		&& data->destroy->destroy_y >= 0)
		data->map->map[data->destroy->destroy_y][data->destroy->destroy_x] = data->destroy->saved_block;
	data->destroy->begin_destroy = -1.0;
	data->destroy->destroy_x = -1;
	data->destroy->destroy_y = -1;
	data->destroy->stage = 0;
	data->destroy->destroying = false;
}

void	reset_saved_block(t_data *data)
{
	if (data->destroy->destroy_x >= 0 && data->destroy->destroy_y >= 0
		&& data->destroy->begin_destroy != -1.0)
		data->map->map[data->destroy->destroy_y][data->destroy->destroy_x] = data->destroy->saved_block;
	data->destroy->begin_destroy = -1.0;
	data->destroy->destroy_x = -1;
	data->destroy->destroy_y = -1;
	data->destroy->stage = 0;
}

void	begin_destroy(t_data *data, int tile_x, int tile_y,
		double current_time_s)
{
	data->destroy->saved_block = data->map->map[tile_y][tile_x];
	data->map->map[tile_y][tile_x] = '5';
	data->destroy->destroy_x = tile_x;
	data->destroy->destroy_y = tile_y;
	data->destroy->stage = 0;
	data->destroy->begin_destroy = current_time_s;
	data->destroy->destroying = true;
}

void	destroy(t_data *data, int tile_x, int tile_y)
{
	if (data->destroy->stage++ < 4)
		data->map->map[tile_y][tile_x]--;
	else
	{
		data->map->map[tile_y][tile_x] = 'O';
		data->destroy->begin_destroy = -1.0;
		data->destroy->destroy_x = -1;
		data->destroy->destroy_y = -1;
		data->destroy->stage = 0;
		data->destroy->destroying = false;
	}
}

void	destroy_block(t_data *data, int tile_x, int tile_y,
		double current_time_s)
{
	if (data->key->mouse_1 == false)
	{
		reset_block(data);
		return ;
	}
	if (data->destroy->destroy_x != tile_x
		|| data->destroy->destroy_y != tile_y)
		reset_saved_block(data);
	if (data->map->map[tile_y][tile_x] < '1'
		|| data->map->map[tile_y][tile_x] > '5')
		return ;
	if (data->destroy->begin_destroy == -1.0)
	{
		begin_destroy(data, tile_x, tile_y, current_time_s);
		return ;
	}
	if (current_time_s - data->destroy->begin_destroy >= (TT_DESTROY / 4)
		* (data->destroy->stage + 1))
		destroy(data, tile_x, tile_y);
	data->destroy->destroying = true;
}
