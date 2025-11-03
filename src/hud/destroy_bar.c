/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:19:39 by kapinarc          #+#    #+#             */
/*   Updated: 2025/11/03 12:57:06 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include "utils.h"

void	destroy_bar(t_data *data, char state)
{
	int	color;
	int	num_state;
	int	i;
	int	j;

	if (data->destroy->destroying == false)
		return ;
	num_state = state - 48;
	num_state *= 40;
	if ((state < '1' || state > '5') && num_state > (WIDTH >> 1))
		return ;
	color = 0x00FF0000 + num_state * 50;
	i = 0;
	while (i < num_state)
	{
		j = 0;
		while (j < 5)
			my_mlx_put_pixel(data->img, ((WIDTH >> 1) - (num_state >> 1)) + i,
				HEIGHT - (HEIGHT >> 3) + j++, color);
		i++;
	}
}
