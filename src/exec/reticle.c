/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reticle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:12:38 by kapinarc          #+#    #+#             */
/*   Updated: 2025/10/27 01:23:12 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include <sys/time.h>

void	reticle_shape(t_data *data, int x, int max_x)
{
	while (x <= max_x)
	{
		if (data->key->mouse_1 == true || data->key->mouse_2 == true)
		{
			my_mlx_put_pixel(data->img, x - 1, (HEIGHT >> 1) - 1, 0x000FFFF);
			my_mlx_put_pixel(data->img, x, (HEIGHT >> 1), 0x0FFFFFF);
		}
		else
		{
			my_mlx_put_pixel(data->img, x - 1, (HEIGHT >> 1) - 1, 0x0FF0000);
			my_mlx_put_pixel(data->img, x, (HEIGHT >> 1), 0x000000);
		}
		x++;
	}
}

void	reticle_shadow(t_data *data, int y, int max_y)
{
	while (y <= max_y)
	{
		if (data->key->mouse_1 == true || data->key->mouse_2 == true)
		{
			my_mlx_put_pixel(data->img, (WIDTH >> 1) - 1, y - 1, 0x000FFFF);
			my_mlx_put_pixel(data->img, (WIDTH >> 1), y, 0x0FFFFFF);
		}
		else
		{
			my_mlx_put_pixel(data->img, (WIDTH >> 1) - 1, y - 1, 0x0FF0000);
			my_mlx_put_pixel(data->img, (WIDTH >> 1), y, 0x000000);
		}
		y++;
	}
}

void	print_reticle(t_data *data)
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	int	lenght;

	lenght = 10;
	x = (WIDTH >> 1) - lenght;
	y = (HEIGHT >> 1) - lenght;
	max_x = (WIDTH >> 1) + lenght;
	max_y = (HEIGHT >> 1) + lenght;
	reticle_shape(data, x, max_x);
	reticle_shadow(data, y, max_y);
	destroy_bar(data, data->map->map[data->player->pointed_y][data->player->pointed_x]);
}
