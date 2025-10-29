/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:42:12 by kapinarc          #+#    #+#             */
/*   Updated: 2025/10/29 17:05:50 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

void	put_square(t_data *data, int pos_x, int pos_y, int color)
{
	int	x;
	int	y;
	int	tall;
	int	edge;

	y = 0;
	x = 0;
	tall = HEIGHT / 35;
	edge = tall / 10;
	while (y < tall)
	{
		x = 0;
		while (x <= tall)
		{
			if (x <= edge || x >= tall - edge || y <= edge || y >= tall - edge)
				my_mlx_put_pixel(data->img, pos_x - x, pos_y - y, 0x0000000);
			else
				my_mlx_put_pixel(data->img, pos_x - x, pos_y - y, color);
			x++;
		}
		y++;
	}
}

void	stock_block(t_data *data)
{
	int		x;
	int		y;
	char	*blocks;
	int		num_blocks;
	int		color;

	x = (WIDTH) / 2;
	y = HEIGHT - (HEIGHT >> 6);
	num_blocks = data->player->blocks;
	blocks = ft_itoa(num_blocks);
	color = 0x000FFFF;
	put_square(data, x + 14, y + 10, color);
	mlx_string_put(data->mlx, data->win, x - ft_strlen(blocks) * 3, y, ~color,
		blocks);
	free(blocks);
}
