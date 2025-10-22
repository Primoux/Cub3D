/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:58:14 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/22 20:00:57 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include "parsing.h"

int	fill(t_data *data, int y, int x, int *n)
{
	if ((*n)++ >= MAP_SIZE || y < 0 || y >= data->map->y_max || x < 0
		|| x >= (int)ft_strlen(data->map->map[y]))
		return (1);
	if (data->map->map[y][x] == '1' || data->map->map[y][x] == 'O')
		return (0);
	if (data->map->map[y][x] != '0' && data->map->map[y][x] != 'S'
		&& data->map->map[y][x] != 'N' && data->map->map[y][x] != 'E'
		&& data->map->map[y][x] != 'W')
		return (1);
	data->map->map[y][x] = 'O';
	if (fill(data, y + 1, x, n) == 1)
		return (1);
	if (fill(data, y - 1, x, n) == 1)
		return (1);
	if (fill(data, y, x - 1, n) == 1)
		return (1);
	if (fill(data, y, x + 1, n) == 1)
		return (1);
	return (0);
}

int	flood_fill(t_data *data)
{
	int	x;
	int	y;
	int	n;

	n = 0;
	y = (int)data->player->py / TILE;
	x = (int)data->player->px / TILE;
	if (fill(data, y, x, &n) == 1)
	{
		if (n >= MAP_SIZE)
		{
			ft_dprintf(2,
				"Error: flood_fill n is greater that MAP_SIZE : %d in %s line %d\n",
				MAP_SIZE,__FILE__, __LINE__);
		}
		else
			ft_dprintf(2,
				"Error: flood_fill at coordinates n = %d (%d,%d) in %s line %d\n",
				n, y, x, __FILE__, __LINE__);
		return (1);
	}
	return (0);
}
