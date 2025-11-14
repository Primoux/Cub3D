/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:27:42 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

void	draw_fps(t_cube *cube, double current_time_s)
{
	static int		frame_count = 0;
	static double	last_update = 0.0;
	static int		fps = 0;
	char			*str;
	char			*str2;

	frame_count++;
	if (current_time_s - last_update >= 1.0)
	{
		fps = frame_count;
		frame_count = 0;
		last_update = current_time_s;
	}
	str = ft_itoa(fps);
	str2 = ft_strjoin("FPS ", str);
	free(str);
	if (str2)
	{
		mlx_string_put(cube->mlx, cube->win, WIDTH - (ft_strlen(str2) * 6) - 3,
			15, 0x00FFFFFF, str2);
		free(str2);
	}
	else
		mlx_string_put(cube->mlx, cube->win, WIDTH - (7 * 6) - 3, 15,
			0x00FF0000, "ERROR?");
}
