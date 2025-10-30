/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:27:42 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 09:16:36 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

void	draw_fps(t_data *data, double current_time_s)
{
	static int		frame_count = 0;
	static double	last_update = 0.0;
	static int		fps = 0;
	char			*str;

	frame_count++;
	if (current_time_s - last_update >= 1.0)
	{
		fps = frame_count;
		frame_count = 0;
		last_update = current_time_s;
	}
	str = ft_itoa(fps);
	if (str)
	{
		mlx_string_put(data->mlx, data->win, WIDTH - (ft_strlen(str) * 6) - 25,
			15, 0x00FFFFFF, "FPS ");
		mlx_string_put(data->mlx, data->win, WIDTH - (ft_strlen(str) * 6) - 1,
			15, 0x00FFFFFF, str);
		free(str);
	}
}
