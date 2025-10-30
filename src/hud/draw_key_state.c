/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_key_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:49:04 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 14:50:05 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

void	draw_key_state(t_data *data, int x, bool is_pressed, const char *key)
{
	int	color;
	int	y;

	y = 60;
	if (is_pressed == true)
		color = 0x0000FF00;
	else
		color = 0x00FF0000;
	mlx_string_put(data->mlx, data->win, x, y, color, (char *)key);
}
