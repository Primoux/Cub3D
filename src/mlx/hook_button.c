/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 03:40:39 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 14:38:55 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include "raycast.h"
#include "destroy.h"

void	handle_mouse_button(t_data *data, double current_time_s)
{
	raycast_to_pointed_block(data);
	if (data->destroy->pt_y < 0 || data->destroy->pt_x < 0
		|| data->destroy->pt_x >= data->map->x_max
		|| data->destroy->pt_y >= data->map->y_max)
		return ;
	destroy_block(data, data->destroy->pt_x, data->destroy->pt_y,
		current_time_s);
	if (data->key->mouse_3 == true && data->player->blocks
		&& data->map->map[data->destroy->pt_y][data->destroy->pt_x] == 'O')
	{
		data->map->map[data->destroy->pt_y][data->destroy->pt_x] = '1';
		data->player->blocks--;
	}
}

int	handle_press_button(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == MOUSE_BUTTON_LEFT)
		data->key->mouse_1 = true;
	if (button == MOUSE_BUTTON_RIGHT)
		data->key->mouse_3 = true;
	return (0);
}

int	handle_release_button(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == MOUSE_BUTTON_LEFT)
		data->key->mouse_1 = false;
	if (button == MOUSE_BUTTON_RIGHT)
		data->key->mouse_3 = false;
	return (0);
}
