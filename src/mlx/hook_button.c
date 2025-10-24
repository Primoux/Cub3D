/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 03:40:39 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/24 03:57:46 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

int	handle_press_button(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (!data || !data->key)
		return (0);
	if (button == MOUSE_BUTTON_LEFT)
		data->key->mouse_1 = true;
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
	return (0);
}
