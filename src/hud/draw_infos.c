/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:59:36 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hud.h"
#include "mlx_management.h"
#include "raycast.h"
#include "utils.h"
#include <math.h>

void	draw_position(t_cube *cube)
{
	char	*str1;
	char	*str2;
	char	*itoa_x;
	char	*itoa_y;

	itoa_x = ft_itoa(cube->player->x / TILE);
	itoa_y = ft_itoa(cube->player->y / TILE);
	str1 = ft_strjoin("X ", itoa_x);
	str2 = ft_strjoin(" / Y ", itoa_y);
	str1 = str_free_to_join(str1, str2);
	free(str2);
	free(itoa_x);
	free(itoa_y);
	str1 = str_free_to_join(str1, " / Z 0");
	if (str1)
	{
		mlx_string_put(cube->mlx, cube->win, WIDTH - (ft_strlen(str1) * 6) - 3,
			30, 0x00FFFFFF, str1);
		free(str1);
	}
	else
		mlx_string_put(cube->mlx, cube->win, WIDTH - (7 * 6) - 3, 30,
			0x00FF0000, "ERROR?");
}

void	draw_angle(t_cube *cube)
{
	char	*str1;
	char	*str2;
	char	*itoa_rad;
	char	*itoa_deg;

	itoa_rad = ft_itoa(cube->player->angle);
	itoa_deg = ft_itoa(cube->player->angle * 180 / M_PI);
	norm_angle(&cube->player->angle);
	str1 = ft_strjoin("ANGLE RAD ", itoa_rad);
	str2 = ft_strjoin(" / ANGLE ", itoa_deg);
	str1 = str_free_to_join(str1, str2);
	free(str2);
	free(itoa_deg);
	free(itoa_rad);
	if (str1)
	{
		mlx_string_put(cube->mlx, cube->win, WIDTH - (ft_strlen(str1) * 6) - 3,
			45, 0x00FFFFFF, str1);
		free(str1);
	}
	else
		mlx_string_put(cube->mlx, cube->win, WIDTH - (7 * 6) - 3, 45,
			0x00FF0000, "ERROR?");
}

void	draw_box(t_cube *cube)
{
	int	x;
	int	y;
	int	y_size;
	int	x_size;

	x = 0;
	y = 0;
	y_size = 65;
	x_size = 160;
	while (y < y_size)
	{
		x = 0;
		while (x < x_size)
		{
			my_mlx_put_pixel(cube->img, WIDTH - x_size + x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void	draw_move_key(t_cube *cube)
{
	int	base_x;
	int	char_width;

	char_width = 6;
	base_x = WIDTH - 45;
	draw_key_state(cube, base_x, cube->key->w_key, "W");
	draw_key_state(cube, base_x + char_width, cube->key->a_key, "A");
	draw_key_state(cube, base_x + char_width * 2, cube->key->s_key, "S");
	draw_key_state(cube, base_x + char_width * 3, cube->key->d_key, "D");
	draw_key_state(cube, base_x + char_width * 4, cube->key->f_key, "F");
	draw_key_state(cube, base_x + char_width * 5, cube->key->left_key, "L");
	draw_key_state(cube, base_x + char_width * 6, cube->key->right_key, "R");
	base_x = WIDTH - 155;
	draw_key_state(cube, base_x, cube->key->shift_l_key, "SHIFT");
	draw_key_state(cube, base_x + 45, cube->key->mouse_1, "M1");
	draw_key_state(cube, base_x + 70, cube->key->mouse_3, "M2");
	draw_key_state(cube, base_x + 85, cube->key->tab_key, "TAB");
}

void	draw_infos(t_cube *cube, double current_time_s)
{
	if (cube->key->f3_key == false)
		return ;
	draw_box(cube);
	draw_fps(cube, current_time_s);
	draw_angle(cube);
	draw_position(cube);
	draw_move_key(cube);
}
