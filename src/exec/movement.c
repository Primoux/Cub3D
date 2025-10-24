/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:55:55 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/24 19:26:56 by enchevri         ###   ########lyon.fr   */
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
		data->player->x = new_x;
		data->player->y = new_y;
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
		new_x = data->player->x + cos(data->player->angle) * move * delta_time;
		check_colision(data, data->player->y, new_x);
		new_y = data->player->y + sin(data->player->angle) * move * delta_time;
		check_colision(data, new_y, data->player->x);
	}
	if (data->key->s_key == true)
	{
		new_x = data->player->x - cos(data->player->angle) * move * delta_time;
		check_colision(data, data->player->y, new_x);
		new_y = data->player->y - sin(data->player->angle) * move * delta_time;
		check_colision(data, new_y, data->player->x);
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
		new_x = data->player->x + cos(data->player->angle + M_PI / 2) * move
			* delta_time;
		check_colision(data, data->player->y, new_x);
		new_y = data->player->y + sin(data->player->angle + M_PI / 2) * move
			* delta_time;
		check_colision(data, new_y, data->player->x);
	}
	if (data->key->a_key == true)
	{
		new_x = data->player->x - cos(data->player->angle + M_PI / 2) * move
			* delta_time;
		check_colision(data, data->player->y, new_x);
		new_y = data->player->y - sin(data->player->angle + M_PI / 2) * move
			* delta_time;
		check_colision(data, new_y, data->player->x);
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

void	destroy_block(t_data *data, int tile_x, int tile_y)
{
	static double	begin_destroy = 0.0;
	double			tt_destroy = 4;
	double			count = 0;
	double			current_time_s;

	if (data->key->mouse_1 == false)
	{
		begin_destroy = -1;
		data->player->destroying = false;
		return ;
	}
	if (data->map->map[tile_y][tile_x] == '1'
		||data->map->map[tile_y][tile_x] == '2'
		||data->map->map[tile_y][tile_x] == '3'
		||data->map->map[tile_y][tile_x] == '4'
		||data->map->map[tile_y][tile_x] == '5')
	{
		current_time_s = get_time_to_msec() / 1000;
		if (begin_destroy == -1)
		{
			data->map->map[tile_y][tile_x] = '5';
			begin_destroy = current_time_s;
		}
//		else if ((data->map->map[tile_y][tile_x] > '1') && (data->map->map[tile_y][tile_x] <= '5'))
//		{
//			if ((current_time_s - begin_destroy) + count > (tt_destroy / 4))
			if (current_time_s - begin_destroy > count)
			{
				--data->map->map[tile_y][tile_x];
				printf("%c\n", data->map->map[tile_y][tile_x]);
				++count;
			}
//		}
		data->player->destroying = true;
		if (current_time_s - begin_destroy >= tt_destroy)
		{
			data->map->map[tile_y][tile_x] = 'O';
			data->player->destroying = false;
			begin_destroy = current_time_s;
		}
	}
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
