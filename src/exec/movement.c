/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:55:55 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"
#include "hud.h"
#include "mlx_management.h"
#include "raycast.h"
#include "utils.h"
#include <math.h>
#include <sys/time.h>

static void	check_colision(t_cube *cube, double new_y, double new_x)
{
	int	tile_x;
	int	tile_y;

	tile_x = floor(new_x / TILE);
	tile_y = floor(new_y / TILE);
	if (tile_y < 0 || tile_x < 0 || tile_x >= cube->map->x_max
		|| tile_y >= cube->map->y_max)
		return ;
	if ((cube->map->map[tile_y][tile_x] == 'O'
		|| cube->map->map[tile_y][tile_x] == 'N'
		|| cube->map->map[tile_y][tile_x] == 'S'
		|| cube->map->map[tile_y][tile_x] == 'E'
		|| cube->map->map[tile_y][tile_x] == 'W'))
	{
		cube->player->x = new_x;
		cube->player->y = new_y;
	}
}

static void	move_forward_or_backward(t_cube *cube, double delta_time)
{
	float	move;
	double	new_x;
	double	new_y;

	move = MOVE_SPEED;
	if (cube->key->shift_l_key == true)
		move = MOVE_SPRINT;
	if (cube->key->w_key == true)
	{
		new_x = cube->player->x + cos(cube->player->angle) * move * delta_time;
		check_colision(cube, cube->player->y, new_x);
		new_y = cube->player->y + sin(cube->player->angle) * move * delta_time;
		check_colision(cube, new_y, cube->player->x);
	}
	if (cube->key->s_key == true)
	{
		new_x = cube->player->x - cos(cube->player->angle) * move * delta_time;
		check_colision(cube, cube->player->y, new_x);
		new_y = cube->player->y - sin(cube->player->angle) * move * delta_time;
		check_colision(cube, new_y, cube->player->x);
	}
}

static void	move_right_or_left(t_cube *cube, double delta_time)
{
	float	move;
	double	new_x;
	double	new_y;

	move = MOVE_SPEED;
	if (cube->key->shift_l_key == true)
		move = MOVE_SPRINT;
	if (cube->key->d_key == true)
	{
		new_x = cube->player->x + cos(cube->player->angle + M_PI / 2) * move
			* delta_time;
		check_colision(cube, cube->player->y, new_x);
		new_y = cube->player->y + sin(cube->player->angle + M_PI / 2) * move
			* delta_time;
		check_colision(cube, new_y, cube->player->x);
	}
	if (cube->key->a_key == true)
	{
		new_x = cube->player->x - cos(cube->player->angle + M_PI / 2) * move
			* delta_time;
		check_colision(cube, cube->player->y, new_x);
		new_y = cube->player->y - sin(cube->player->angle + M_PI / 2) * move
			* delta_time;
		check_colision(cube, new_y, cube->player->x);
	}
}

static void	move_cam(t_cube *cube, double delta_time)
{
	static int	x = 0;
	static int	y = 0;
	double		mvx;

	if (cube->key->left_key == true)
		cube->player->angle -= ANGLE_KEY * delta_time;
	if (cube->key->right_key == true)
		cube->player->angle += ANGLE_KEY * delta_time;
	if (cube->key->f_key == false)
	{
		mlx_mouse_show(cube->mlx, cube->win);
		return ;
	}
	mlx_mouse_hide(cube->mlx, cube->win);
	if (x == 0 && y == 0)
		mlx_mouse_move(cube->mlx, cube->win, WIDTH >> 1, HEIGHT >> 1);
	if (mlx_mouse_get_pos(cube->mlx, cube->win, &x, &y) == 1)
	{
		mvx = ANGLE_MOUSE * (double)(x - (WIDTH >> 1));
		if (mvx)
		{
			mlx_mouse_move(cube->mlx, cube->win, WIDTH >> 1, HEIGHT >> 1);
			cube->player->angle += mvx;
		}
	}
}

int	player_loop(t_cube *cube)
{
	double	current_time;
	double	delta_time;

	if (!cube->player->last_frame_time)
		cube->player->last_frame_time = get_time_to_msec();
	current_time = get_time_to_msec();
	delta_time = (current_time - cube->player->last_frame_time) / 1000;
	move_forward_or_backward(cube, delta_time);
	move_right_or_left(cube, delta_time);
	move_cam(cube, delta_time);
	handle_mouse_button(cube, current_time / 1000);
	raycast_loop(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img->img, 0, 0);
	display_hud(cube, current_time / 1000);
	cube->player->last_frame_time = current_time;
	return (0);
}
