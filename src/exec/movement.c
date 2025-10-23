/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:55:55 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/22 17:17:07 by enchevri         ###   ########lyon.fr   */
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

static void	move_forward_or_backward(t_data *data, double new_x, double new_y,
		double delta_time)
{
	float	move;

	move = MOVE_SPEED;
	if (data->key->shift_l_key == true)
		move = MOVE_SPRINT;
	if (data->key->w_key == true)
	{
		new_x = data->player->px + cos(data->player->angle) * move * delta_time;
		new_y = data->player->py + sin(data->player->angle) * move * delta_time;
		check_colision(data, new_y, new_x);
	}
	if (data->key->s_key == true)
	{
		new_x = data->player->px - cos(data->player->angle) * move * delta_time;
		new_y = data->player->py - sin(data->player->angle) * move * delta_time;
		check_colision(data, new_y, new_x);
	}
}


//ne plus gerer avec un delta time mais delta pos
void		move_cam(t_data *data)
{
	static int	x = 0;
	static int	y = 0;
	double		mvx;

	if (x == 0 && y == 0)
		mlx_mouse_move(data->mlx, data->win, WIDTH >> 1, HEIGHT >> 1);
	if (mlx_mouse_get_pos(data->mlx, data->win, &x, &y) == 1)
	{
		mvx = ANGLE_MOUSE * (double)(x - WIDTH / 2);
		if (mvx)
		{
		mlx_mouse_hide(data->mlx, data->win);
		mlx_mouse_move(data->mlx, data->win, WIDTH >> 1, HEIGHT >> 1);
			data->player->angle += mvx;
		}
	}
}


static void	move_right_or_left(t_data *data, double new_x, double new_y,
		double delta_time)
{
	float	move;

	move = MOVE_SPEED;
	if (data->key->shift_l_key == true)
		move = MOVE_SPRINT;
	if (data->key->d_key == true)
	{
		new_x = data->player->px + cos(data->player->angle + M_PI / 2) * move
			* delta_time;
		new_y = data->player->py + sin(data->player->angle + M_PI / 2) * move
			* delta_time;
		check_colision(data, new_y, new_x);
	}
	if (data->key->a_key == true)
	{
		new_x = data->player->px - cos(data->player->angle + M_PI / 2) * move
			* delta_time;
		new_y = data->player->py - sin(data->player->angle + M_PI / 2) * move
			* delta_time;
		check_colision(data, new_y, new_x);
	}
	//implementer le fait de bouger avec la souris
	if (data->key->left_key == true)
		data->player->angle -= ANGLE_KEY * delta_time;
	if (data->key->right_key == true)
		data->player->angle += ANGLE_KEY * delta_time;
}

double	get_time_to_msec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec * 1000.0 + (double)tv.tv_usec / 1000.0);
}

int	move_player(t_data *data)
{
	double	new_x;
	double	new_y;
	double	current_time;
	double	delta_time;

	if (!data->player->last_frame_time)
		data->player->last_frame_time = get_time_to_msec();
	current_time = get_time_to_msec();
	delta_time = (current_time - data->player->last_frame_time) / 1000;
	new_x = 0.0;
	new_y = 0.0;
	move_forward_or_backward(data, new_x, new_y, delta_time);
	move_right_or_left(data, new_x, new_y, delta_time);
	move_cam(data);
	raycast_loop(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	draw_fps(data, current_time);
	data->player->last_frame_time = current_time;
	return (0);
}
