/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:58:14 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/21 22:39:15 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

int	fill(char **map, int y, int x, int width)
{
	if (y < 0 || y > width|| x < 0 || x >= (int)ft_strlen(map[y]))
		return (1);
	if (map[y][x] == '1' || map[y][x] == 'O')
		return (0);
	if (map[y][x] != '0' && map[y][x] != 'S' && map[y][x] != 'N'
		&& map[y][x] != 'E' && map[y][x] != 'W')
		return (1);
	map[y][x] = 'O';
	if (fill(map, y + 1, x, width) == 1)
		return (1);
	if (fill(map, y - 1, x, width) == 1)
		return (1);
	if (fill(map, y, x - 1, width) == 1)
		return (1);
	if (fill(map, y, x + 1, width) == 1)
		return (1);
	return (0);
}

int	flood_fill(t_data *data)
{
	int	x;
	int	y;

	y = (int)data->player->py / TILE;
	x = (int)data->player->px / TILE;
	if (fill(data->map->map, y, x, data->map->y_max) == 1)
	{
		ft_dprintf(2,
			"Error: flood_fill returned an error at coordinates (%d,%d) in%s\n"
            , x, y, __FILE__);
		return (1);
	}
	return (0);
}
