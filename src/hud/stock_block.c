/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:42:12 by kapinarc          #+#    #+#             */
/*   Updated: 2025/10/30 14:41:43 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"
#include "mlx_management.h"

void	put_square(t_data *data, int pos_x, int pos_y, int color)
{
	int	x;
	int	y;
	int	size;

	size = HEIGHT / 30;
	y = -size / 2;
	while (y < size / 2)
	{
		x = -size / 2;
		while (x < size / 2)
		{
			if (x == -size / 2 || x == size / 2 - 1 || y == -size / 2
				|| y == size / 2 - 1)
				my_mlx_put_pixel(data->img, pos_x + x, pos_y + y, 0x000000);
			else
				my_mlx_put_pixel(data->img, pos_x + x, pos_y + y, color);
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
	int		color;

	x = WIDTH / 2;
	y = HEIGHT - (HEIGHT / 15);
	blocks = ft_itoa(data->player->blocks);
	color = 0x000FFFF;
	put_square(data, x, y, color);
	mlx_string_put(data->mlx, data->win, x - (ft_strlen(blocks) * 3), y + 4,
		~color, blocks);
	free(blocks);
}
