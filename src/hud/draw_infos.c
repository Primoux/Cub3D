/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:59:36 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 13:17:55 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

void	draw_position(t_data *data)
{
	char	*str1;
	char	*str2;
	char	*itoa_x;
	char	*itoa_y;

	itoa_x = ft_itoa(data->player->x / TILE);
	itoa_y = ft_itoa(data->player->y / TILE);
	str1 = ft_strjoin("X ", itoa_x);
	str2 = ft_strjoin(" / Y ", itoa_y);
	str1 = str_free_to_join(str1, str2);
	free(str2);
	free(itoa_x);
	free(itoa_y);
	str1 = str_free_to_join(str1, " / Z 0");
	if (str1)
	{
		mlx_string_put(data->mlx, data->win, WIDTH - (ft_strlen(str1) * 6) - 3,
			30, 0x00FFFFFF, str1);
		free(str1);
	}
}

void	draw_angle(t_data *data)
{
	char	*str1;
	char	*str2;
	char	*itoa_rad;
	char	*itoa_deg;

	itoa_rad = ft_itoa(data->player->angle);
	itoa_deg = ft_itoa(data->player->angle * 180 / M_PI);
	norm_angle(&data->player->angle);
	str1 = ft_strjoin("ANGLE RAD ", itoa_rad);
	str2 = ft_strjoin(" / ANGLE ", itoa_deg);
	str1 = str_free_to_join(str1, str2);
	free(str2);
	free(itoa_deg);
	free(itoa_rad);
	if (str1)
	{
		mlx_string_put(data->mlx, data->win, WIDTH - (ft_strlen(str1) * 6) - 3,
			45, 0x00FFFFFF, str1);
		free(str1);
	}
}

void	draw_box(t_data *data)
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
			my_mlx_put_pixel(data->img, WIDTH - x_size + x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

static void	draw_key_state(t_data *data, int x, int y, bool is_pressed,
		const char *key)
{
	int	color;

	if (is_pressed == true)
	{
		color = 0x0000FF00;
	}
	else
		color = 0x00FF0000;
	mlx_string_put(data->mlx, data->win, x, y, color, (char *)key);
}

void	draw_move_key(t_data *data)
{
	int	base_x;
	int	char_width;

	char_width = 6;
	base_x = WIDTH - 45;
	draw_key_state(data, base_x, 60, data->key->w_key, "W");
	draw_key_state(data, base_x + char_width, 60, data->key->a_key, "A");
	draw_key_state(data, base_x + char_width * 2, 60, data->key->s_key, "S");
	draw_key_state(data, base_x + char_width * 3, 60, data->key->d_key, "D");
	draw_key_state(data, base_x + char_width * 4, 60, data->key->f_key, "F");
	draw_key_state(data, base_x + char_width * 5, 60, data->key->left_key, "L");
	draw_key_state(data, base_x + char_width * 6, 60, data->key->right_key, "R");
	base_x = WIDTH - 155;
	draw_key_state(data, base_x, 60, data->key->shift_l_key, "SHIFT");
	draw_key_state(data, base_x + 45, 60, data->key->mouse_1, "M1");
	draw_key_state(data, base_x + 65, 60, data->key->mouse_3, "M2");
	draw_key_state(data, base_x + 80, 60, data->key->tab_key, "TAB");
}

void	draw_infos(t_data *data, double current_time_s)
{
	if (data->key->f3_key == false)
		return ;
	draw_box(data);
	draw_fps(data, current_time_s);
	draw_angle(data);
	draw_position(data);
	draw_move_key(data);
}
