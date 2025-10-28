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

void	put_square(t_data *data, int pos_x, int pos_y, int color)
{
	int x = 0;
	int y = 0;
	int	tall;

	tall = 30;
	while(y < tall)
	{
		x = 0;

		while(x <= tall)
		{
			if (x <= 2 || x >= tall - 3 || y <= 2 || y >= tall - 3)
				my_mlx_put_pixel(data->img, pos_x - x , pos_y - y, 0x0000000);
			else
				my_mlx_put_pixel(data->img, pos_x - x , pos_y - y, color);
			x++;
		}
		y++;
	}
}

void	stock_block(t_data *data)
{
	int		num_blocks;
	char	*blocks = NULL;
	int x;
	int y;
	int color;

	x = WIDTH / 2 - 5;
	y = HEIGHT - 10 - 5;
	num_blocks = data->player->blocks;
	blocks = ft_itoa(num_blocks);

	color = 0x000FFFF;
	if (data->player->destroying == true)
	{
		put_square(data, x + 16, y + 10, ~color);
		mlx_string_put(data->mlx, data->win, x, y - 2, color, blocks);
	}
	else
	{
		put_square(data, x + 16, y + 10, color);
		mlx_string_put(data->mlx, data->win, x, y, ~color, blocks);
	}
	free(blocks);
}
