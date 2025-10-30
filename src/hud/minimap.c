/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:12 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 15:21:52 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include "utils.h"
#include <math.h>

static int	get_minimap_scale(t_data *data)
{
	int	max_dim;
	int	scale;

	if (data->map->x_max > data->map->y_max)
		max_dim = data->map->x_max;
	else
		max_dim = data->map->y_max;
	scale = 400 / max_dim;
	if (scale < 1)
		scale = 1;
	return (scale);
}

static void	draw_tile(t_data *data, int scale, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < scale)
	{
		j = 0;
		while (j < scale)
		{
			my_mlx_put_pixel(data->img, data->map->x * scale + i, data->map->y
				* scale + j, color);
			j++;
		}
		i++;
	}
}

static void	draw_minimap_tile(t_data *data, int scale)
{
	int				player_x;
	int				player_y;
	unsigned int	wall_color;
	int				player_color;

	player_x = floor(data->player->x / TILE);
	player_y = floor(data->player->y / TILE);
	wall_color = ~data->texture->ceiling.val;
	player_color = 0x0000FF00;
	if (data->map->map[data->map->y][data->map->x] == '6')
		draw_tile(data, scale, 0x003333FF);
	if (data->map->map[data->map->y][data->map->x] == '5')
		draw_tile(data, scale, 0x005555FF);
	if (data->map->map[data->map->y][data->map->x] == '4')
		draw_tile(data, scale, 0x007777FF);
	if (data->map->map[data->map->y][data->map->x] == '3')
		draw_tile(data, scale, 0x009999FF);
	if (data->map->map[data->map->y][data->map->x] == '2')
		draw_tile(data, scale, 0x00BBBBFF);
	if (data->map->map[data->map->y][data->map->x] == '1')
		draw_tile(data, scale, wall_color);
	if (data->map->y == player_y && data->map->x == player_x)
		draw_tile(data, scale, player_color);
}

void	draw_minimap(t_data *data)
{
	int	scale;

	if (data->key->tab_key == false)
		return ;
	scale = get_minimap_scale(data);
	data->map->y = 0;
	while (data->map->map[data->map->y])
	{
		data->map->x = 0;
		while (data->map->map[data->map->y][data->map->x])
		{
			draw_minimap_tile(data, scale);
			data->map->x++;
		}
		data->map->y++;
	}
}
