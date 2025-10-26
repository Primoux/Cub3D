/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 03:40:39 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/26 17:23:52 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

void	handle_mouse(t_data *data)
{
	double	destroy_x;
	double	destroy_y;
	double	distance;

	distance = 1 * TILE;
	destroy_x = data->player->x + cos(data->player->angle) * distance;
	destroy_y = data->player->y + sin(data->player->angle) * distance;
	data->player->pointed_x = destroy_x / TILE;
	data->player->pointed_y = destroy_y / TILE;
	if (data->player->pointed_y < 0 || data->player->pointed_x < 0
		|| data->player->pointed_x >= data->map->x_max
		|| data->player->pointed_y >= data->map->y_max)
		return ;
	destroy_block(data, data->player->pointed_x, data->player->pointed_y);
	if (data->key->mouse_2 == true
		&& data->map->map[data->player->pointed_y][data->player->pointed_x] == 'O')
		data->map->map[data->player->pointed_y][data->player->pointed_x] = '1';
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
