/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 03:40:39 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include "raycast.h"
#include "destroy.h"

void	handle_mouse_button(t_cube *cube, double current_time_s)
{
	raycast_to_pointed_block(cube);
	if (cube->destroy->pt_y < 0 || cube->destroy->pt_x < 0
		|| cube->destroy->pt_x >= cube->map->x_max
		|| cube->destroy->pt_y >= cube->map->y_max)
		return ;
	destroy_block(cube, cube->destroy->pt_x, cube->destroy->pt_y,
		current_time_s);
	if (cube->key->mouse_3 == true && cube->player->blocks
		&& cube->map->map[cube->destroy->pt_y][cube->destroy->pt_x] == 'O')
	{
		cube->map->map[cube->destroy->pt_y][cube->destroy->pt_x] = '1';
		cube->player->blocks--;
	}
}

int	handle_press_button(int button, int x, int y, t_cube *cube)
{
	(void)x;
	(void)y;
	if (button == MOUSE_BUTTON_LEFT)
		cube->key->mouse_1 = true;
	if (button == MOUSE_BUTTON_RIGHT)
		cube->key->mouse_3 = true;
	return (0);
}

int	handle_release_button(int button, int x, int y, t_cube *cube)
{
	(void)x;
	(void)y;
	if (button == MOUSE_BUTTON_LEFT)
		cube->key->mouse_1 = false;
	if (button == MOUSE_BUTTON_RIGHT)
		cube->key->mouse_3 = false;
	return (0);
}
