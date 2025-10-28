/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:19:39 by kapinarc          #+#    #+#             */
/*   Updated: 2025/10/27 19:19:39 by kapinarc         ###   ########.fr       */
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
	if (data->player->destroying == 1)
	{
		while (i < num_stat)
		{
			j = 0;
			while (j < 5)
				my_mlx_put_pixel(data->img, ((WIDTH >> 1) - (num_stat / 2))
					+ i, HEIGHT - 100 + j++, color);
			i++;
		}
	}
}

void	stock_block(t_data *data)
{
//	printf("frame %f\n", fmod(round(data->player->last_frame_time), 5));
//	if (fmod(round(data->player->last_frame_time), 5) == 4 && data->player->destroying == true)
//	{
//		mlx_string_put(data->mlx, data->win, WIDTH / 2, HEIGHT - 5, 0x000FFFF, ft_itoa(data->player->blocks));
//	}
//	else
	if (data->player->destroying == true)
		mlx_string_put(data->mlx, data->win, WIDTH / 2, HEIGHT - 5, 0x000FFFF, ft_itoa(data->player->blocks));
	else
		mlx_string_put(data->mlx, data->win, WIDTH / 2, HEIGHT - 5, 0x0FF0000, ft_itoa(data->player->blocks));
	printf("blocks = %d\n", data->player->blocks);
}
