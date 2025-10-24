/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 03:40:39 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/24 11:59:05 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

void	handle_mouse(t_data *data)
{
	int		tile_x;
	int		tile_y;
	double	destroy_x;
	double	destroy_y;
	double	distance;

	if (data->key->mouse_1 == false && data->key->mouse_2 == false)
		return ;
	distance = 2 * TILE;
	destroy_x = data->player->px + cos(data->player->angle) * distance;
	destroy_y = data->player->py + sin(data->player->angle) * distance;
	tile_x = destroy_x / TILE;
	tile_y = destroy_y / TILE;
	if (tile_y < 0 || tile_x < 0 || tile_x >= data->map->x_max
		|| tile_y >= data->map->y_max)
		return ;
	destroy_time(data, tile_x, tile_y);
	if (data->key->mouse_2 == true && data->map->map[tile_y][tile_x] == 'O')
		data->map->map[tile_y][tile_x] = '1';
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
