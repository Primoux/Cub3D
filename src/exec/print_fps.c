/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:27:42 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/22 16:27:50 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_fps(t_data *data, double current_time_ms)
{
	static int		frame_count = 0;
	static double	last_update = 0.0;
	static int		fps = 0;
	double			current_time_s;
	char			*str;

	frame_count++;
	current_time_s = current_time_ms / 1000.0;
	if (current_time_s - last_update >= 1.0)
	{
		fps = frame_count;
		frame_count = 0;
		last_update = current_time_s;
	}
	if (data->key->f_key == false)
		return ;
	str = ft_itoa(fps);
	if (str)
		mlx_string_put(data->mlx, data->win, 10, 10,
			~data->texture->ceiling.val, str);
}
