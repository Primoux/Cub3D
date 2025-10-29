/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 03:40:39 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/29 16:29:08 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

static void	set_pointed_block(t_data *data, double x, double y)
{
	data->destroy->pointed_x = x / TILE;
	data->destroy->pointed_y = y / TILE;
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

	dist = 0;
	while (dist < RANGE_DESTROY * TILE)
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
		dist += 1;
	}
	set_pointed_block(data, data->player->x + cos(data->player->angle)
		* RANGE_DESTROY / TILE, data->player->y + sin(data->player->angle)
		* RANGE_DESTROY / TILE);
}

void	handle_mouse_button(t_data *data, double current_time_s)
{
	raycast_to_pointed_block(data);
	if (data->destroy->pointed_y < 0 || data->destroy->pointed_x < 0
		|| data->destroy->pointed_x >= data->map->x_max
		|| data->destroy->pointed_y >= data->map->y_max)
		return ;
	destroy_block(data, data->destroy->pointed_x, data->destroy->pointed_y,
		current_time_s);
	if (data->key->mouse_2 == true &&  data->player->blocks
		&& data->map->map[data->destroy->pointed_y][data->destroy->pointed_x] == 'O')
	{
		data->map->map[data->destroy->pointed_y][data->destroy->pointed_x] = '1';
		data->player->blocks--;
	}
}

int	handle_press_button(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (!data || !data->key)
		return (0);
	if (button == MOUSE_BUTTON_LEFT)
		data->key->mouse_1 = true;
	if (button == MOUSE_BUTTON_RIGHT)
		data->key->mouse_2 = true;
	return (0);
}

int	handle_release_button(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (!data || !data->key)
		return (0);
	if (button == MOUSE_BUTTON_LEFT)
		data->key->mouse_1 = false;
	if (button == MOUSE_BUTTON_RIGHT)
		data->key->mouse_2 = false;
	return (0);
}
