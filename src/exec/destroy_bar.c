/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:19:39 by kapinarc          #+#    #+#             */
/*   Updated: 2025/10/29 14:59:00 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

void	destroy_bar(t_data *data, char state)
{
	int		color;
	int		error;
	int		i;
	int		num_stat;
	int		j;

	error = 0;
	num_stat = ft_atoi(&state, &error);
	color = 0xFF00000 + num_stat * 50;
	if (error != 0)
		return ;
	i = 0;
	num_stat *= 40;
	if (data->destroy->destroying == 1)
	{
		while (i < num_stat)
		{
			j = 0;
			while (j < 5)
				my_mlx_put_pixel(data->img, ((WIDTH >> 1) - (num_stat / 2))
					+ i, HEIGHT - (HEIGHT >> 2)  + j++, color);
			i++;
		}
	}
}
