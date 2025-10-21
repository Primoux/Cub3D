/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:55:55 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/21 22:39:19 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

static void	check_colision(t_player *player, t_map *map, double new_y,
		double new_x)
{
	int	tile_x;
	int	tile_y;

	tile_x = floor(new_x / TILE);
	tile_y = floor(new_y / TILE);
	if ((map->map[tile_y][tile_x] == 'O' || map->map[tile_y][tile_x] == 'N'
			|| map->map[tile_y][tile_x] == 'S'
			|| map->map[tile_y][tile_x] == 'E'
			|| map->map[tile_y][tile_x] == 'W'))
	{
		player->px = new_x;
		player->py = new_y;
	}
}

static void	move_forward_or_backward(t_data *data, double new_x, double new_y,
		float move)
{
	if (data->key->w_key == true)
	{
		new_x = data->player->px + cos(data->player->angle) * move;
		new_y = data->player->py + sin(data->player->angle) * move;
		check_colision(data->player, data->map, new_y, new_x);
	}
	if (data->key->s_key == true)
	{
		new_x = data->player->px - cos(data->player->angle) * move;
		new_y = data->player->py - sin(data->player->angle) * move;
		check_colision(data->player, data->map, new_y, new_x);
	}
}

static void	move_right_or_left(t_data *data, double new_x, double new_y,
		float move)
{
	if (data->key->d_key == true)
	{
		new_x = data->player->px + cos(data->player->angle + M_PI / 2) * move;
		new_y = data->player->py + sin(data->player->angle + M_PI / 2) * move;
		check_colision(data->player, data->map, new_y, new_x);
	}
	if (data->key->a_key == true)
	{
		new_x = data->player->px - cos(data->player->angle + M_PI / 2) * move;
		new_y = data->player->py - sin(data->player->angle + M_PI / 2) * move;
		check_colision(data->player, data->map, new_y, new_x);
	}
	if (data->key->left_key == true)
		data->player->angle -= ANGLE_SPEED;
	if (data->key->right_key == true)
		data->player->angle += ANGLE_SPEED;
}

int	move_player(t_data *data)
{
	double	new_x;
	double	new_y;
	float	move;

	new_x = 0.0;
	new_y = 0.0;
	move = MOVE_SPEED;
	if (data->key->shift_l_key == true)
		move = MOVE_SPRINT;
	move_forward_or_backward(data, new_x, new_y, move);
	move_right_or_left(data, new_x, new_y, move);
	raycaster(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}
