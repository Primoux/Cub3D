/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:19:39 by kapinarc          #+#    #+#             */
/*   Updated: 2025/10/29 17:12:42 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

void	destroy_bar(t_data *data, char state)
{
	int	color;
	int	num_state;
	int	i;
	int	j;

	if (state == 'O')
		return ;
	num_state = state - 48;
	color = 0xFF00000 + num_state * 50;
	i = 0;
	num_state *= 40;
	if (data->destroy->destroying == true)
	{
		while (i < num_state)
		{
			j = 0;
			while (j < 5)
				my_mlx_put_pixel(data->img, ((WIDTH >> 1) - (num_state / 2))
					+ i, HEIGHT - (HEIGHT >> 3) + j++, color);
			i++;
		}
	}
}
