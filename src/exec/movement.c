/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:55:55 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/27 01:25:50 by enchevri         ###   ########lyon.fr   */
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

void	destroy_block(t_data *data, int tile_x, int tile_y,
		double current_time_s)
{
	static double	begin_destroy = -1.0;
	static int		destroy_tile_x = -1;
	static int		destroy_tile_y = -1;
	static char		saved_block;
	double			tt_destroy;
	static int		stage;

	tt_destroy = TT_DESTROY;
	printf("[DEBUG] mouse_1: %d, tile[%d][%d]: %c\n", data->key->mouse_1,
		tile_x, tile_y, data->map->map[tile_y][tile_x]);
	if (data->key->mouse_1 == false)
	{
		if (data->player->destroying == true && begin_destroy != -1.0
			&& destroy_tile_x >= 0 && destroy_tile_y >= 0)
			data->map->map[destroy_tile_y][destroy_tile_x] = saved_block;
		// printf("[DEBUG] Mouse released, resetting\n");
		begin_destroy = -1.0;
		destroy_tile_x = -1;
		destroy_tile_y = -1;
		stage = 0;
		data->player->destroying = false;
		return ;
	}
	if (destroy_tile_x != tile_x || destroy_tile_y != tile_y)
	{
		// printf("[DEBUG] Changed target block from [%d][%d] to [%d][%d]\n",
		// 	destroy_tile_x, destroy_tile_y, tile_x, tile_y);
		if (destroy_tile_x >= 0 && destroy_tile_y >= 0 && begin_destroy != -1.0)
			data->map->map[destroy_tile_y][destroy_tile_x] = saved_block;
		begin_destroy = -1.0;
		destroy_tile_x = -1;
		destroy_tile_y = -1;
		stage = 0;
	}
	if (data->map->map[tile_y][tile_x] < '1'
		|| data->map->map[tile_y][tile_x] > '6')
	{
		// printf("[DEBUG] Not a valid block: %c\n",
		// 	data->map->map[tile_y][tile_x]);
		return ;
	}
	if (begin_destroy == -1.0)
	{
		// printf("[DEBUG] Starting destruction at %.2f on block [%d][%d]\n",
		// 	current_time_s, tile_x, tile_y);
		saved_block = data->map->map[tile_y][tile_x];
		data->map->map[tile_y][tile_x] = '6';
		destroy_tile_x = tile_x;
		destroy_tile_y = tile_y;
		stage = 0;
		begin_destroy = current_time_s;
		data->player->destroying = true;
		return ;
	}
	// printf("[DEBUG] Time elapsed: %.2f / %.2f, stage: %d\n", current_time_s
	// 	- begin_destroy, (tt_destroy / 4) * (stage + 1), stage);
	if (current_time_s - begin_destroy >= (tt_destroy / 4) * (stage + 1))
	{
		if (stage < 4)
		{
			// printf("[DEBUG] Stage %d -> %d, block: %c -> %c\n", stage, stage
			// 	+ 1, data->map->map[tile_y][tile_x],
			// 	data->map->map[tile_y][tile_x] - 1);
			data->map->map[tile_y][tile_x]--;
			stage++;
		}
		else
		{
			// printf("[DEBUG] Destruction complete! Block: %c -> O\n",
			// 	data->map->map[tile_y][tile_x]);
			data->map->map[tile_y][tile_x] = 'O';
			begin_destroy = -1.0;
			destroy_tile_x = -1;
			destroy_tile_y = -1;
			stage = 0;
			data->player->destroying = false;
		}
	}
	data->player->destroying = true;
}

int	player_loop(t_data *data)
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
	handle_mouse_button(data, current_time / 1000);
	raycast_loop(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	draw_ui(data, current_time / 1000);
	data->player->last_frame_time = current_time;
	return (0);
}
