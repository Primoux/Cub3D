/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:12 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include "utils.h"
#include <math.h>

static int	get_minimap_scale(t_cube *cube)
{
	int	max_dim;
	int	scale;

	if (cube->map->x_max > cube->map->y_max)
		max_dim = cube->map->x_max;
	else
		max_dim = cube->map->y_max;
	scale = 400 / max_dim;
	if (scale < 1)
		scale = 1;
	return (scale);
}

static void	draw_tile(t_cube *cube, int scale, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < scale)
	{
		j = 0;
		while (j < scale)
		{
			my_mlx_put_pixel(cube->img, cube->map->x * scale + i, cube->map->y
				* scale + j, color);
			j++;
		}
		i++;
	}
}

static void	draw_minimap_tile(t_cube *cube, int scale)
{
	int				player_x;
	int				player_y;
	unsigned int	wall_color;
	int				player_color;

	player_x = floor(cube->player->x / TILE);
	player_y = floor(cube->player->y / TILE);
	wall_color = ~cube->texture->ceiling.val;
	player_color = 0x0000FF00;
	if (cube->map->map[cube->map->y][cube->map->x] == '6')
		draw_tile(cube, scale, 0x00AAAAFF);
	if (cube->map->map[cube->map->y][cube->map->x] == '5')
		draw_tile(cube, scale, 0x00CCCCFF);
	if (cube->map->map[cube->map->y][cube->map->x] == '4')
		draw_tile(cube, scale, 0x009999FF);
	if (cube->map->map[cube->map->y][cube->map->x] == '3')
		draw_tile(cube, scale, 0x007777FF);
	if (cube->map->map[cube->map->y][cube->map->x] == '2')
		draw_tile(cube, scale, 0x005555FF);
	if (cube->map->map[cube->map->y][cube->map->x] == '1')
		draw_tile(cube, scale, 0X003333FF);
	if (cube->map->y == player_y && cube->map->x == player_x)
		draw_tile(cube, scale, player_color);
}

void	draw_minimap(t_cube *cube)
{
	int	scale;

	if (cube->key->tab_key == false)
		return ;
	scale = get_minimap_scale(cube);
	cube->map->y = 0;
	while (cube->map->map[cube->map->y])
	{
		cube->map->x = 0;
		while (cube->map->map[cube->map->y][cube->map->x])
		{
			draw_minimap_tile(cube, scale);
			cube->map->x++;
		}
		cube->map->y++;
	}
}
