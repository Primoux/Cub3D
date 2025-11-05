/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:58:14 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/05 10:42:36 by enchevri         ###   ########lyon.fr   */
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
	y = (int)data->player->y / TILE;
	x = (int)data->player->x / TILE;
	if (fill(data, y, x, &n) == 1)
	{
		if (n >= MAP_SIZE)
		{
			ft_dprintf(2, "Error: flood_fill n > MAP_SIZE : %d\n",
				MAP_SIZE);
		}
		else
			ft_dprintf(2, "Error: flood_fill n = %d\n", n);
		return (1);
	}
	return (0);
}
