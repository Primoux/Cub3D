/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:55:55 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/24 10:13:08 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include <sys/time.h>

static void	check_colision(t_data *data, double new_y, double new_x)
{
	int	tile_x;
	int	tile_y;

	tile_x = floor(new_x / TILE);
	tile_y = floor(new_y / TILE);
	if (tile_y < 0 || tile_x < 0 || tile_x >= data->map->x_max
		|| tile_y >= data->map->y_max)
		return ;
	if ((data->map->map[tile_y][tile_x] == 'O'
			|| data->map->map[tile_y][tile_x] == 'N'
			|| data->map->map[tile_y][tile_x] == 'S'
			|| data->map->map[tile_y][tile_x] == 'E'
			|| data->map->map[tile_y][tile_x] == 'W'))
	{
		data->player->px = new_x;
		data->player->py = new_y;
	}
}

static void	move_forward_or_backward(t_data *data, double delta_time)
{
	float	move;
	double	new_x;
	double	new_y;

	move = MOVE_SPEED;
	if (data->key->shift_l_key == true)
		move = MOVE_SPRINT;
	if (data->key->w_key == true)
	{
		new_x = data->player->px + cos(data->player->angle) * move * delta_time;
		check_colision(data, data->player->py, new_x);
		new_y = data->player->py + sin(data->player->angle) * move * delta_time;
		check_colision(data, new_y, data->player->px);
	}
	if (data->key->s_key == true)
	{
		new_x = data->player->px - cos(data->player->angle) * move * delta_time;
		check_colision(data, data->player->py, new_x);
		new_y = data->player->py - sin(data->player->angle) * move * delta_time;
		check_colision(data, new_y, data->player->px);
	}
}

static void	move_right_or_left(t_data *data, double delta_time)
{
	float	move;
	double	new_x;
	double	new_y;

	move = MOVE_SPEED;
	if (data->key->shift_l_key == true)
		move = MOVE_SPRINT;
	if (data->key->d_key == true)
	{
		new_x = data->player->px + cos(data->player->angle + M_PI / 2) * move
			* delta_time;
		check_colision(data, data->player->py, new_x);
		new_y = data->player->py + sin(data->player->angle + M_PI / 2) * move
			* delta_time;
		check_colision(data, new_y, data->player->px);
	}
	if (data->key->a_key == true)
	{
		new_x = data->player->px - cos(data->player->angle + M_PI / 2) * move
			* delta_time;
		new_y = data->player->py - sin(data->player->angle + M_PI / 2) * move
			* delta_time;
		check_colision(data, new_y, new_x);
	}
}

static void	move_cam(t_data *data, double delta_time)
{
	static int	x = 0;
	static int	y = 0;
	double		mvx;

	if (data->key->left_key == true)
		data->player->angle -= ANGLE_KEY * delta_time;
	if (data->key->right_key == true)
		data->player->angle += ANGLE_KEY * delta_time;
	if (x == 0 && y == 0)
		mlx_mouse_move(data->mlx, data->win, WIDTH >> 1, HEIGHT >> 1);
	if (mlx_mouse_get_pos(data->mlx, data->win, &x, &y) == 1)
	{
		mvx = ANGLE_MOUSE * (double)(x - WIDTH / 2);
		if (mvx)
		{
			mlx_mouse_move(data->mlx, data->win, WIDTH >> 1, HEIGHT >> 1);
			data->player->angle += mvx;
		}
	}
}

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
	if (data->key->mouse_1 == true && data->map->map[tile_y][tile_x] == '1')
		data->map->map[tile_y][tile_x] = 'O';
	if (data->key->mouse_2 == true && data->map->map[tile_y][tile_x] == 'O')
		data->map->map[tile_y][tile_x] = '1';
}

int	move_player(t_data *data)
{
	double	current_time;
	double	delta_time;

	if (!data->player->last_frame_time)
		data->player->last_frame_time = get_time_to_msec();
	current_time = get_time_to_msec();
	delta_time = (current_time - data->player->last_frame_time) / 1000;
	move_forward_or_backward(data, delta_time);
	move_right_or_left(data, delta_time);
	move_cam(data, delta_time);
	raycast_loop(data);
	handle_mouse(data);
	draw_minimap(data);
	print_reticle(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	draw_fps(data, current_time);
	data->player->last_frame_time = current_time;
	return (0);
}
