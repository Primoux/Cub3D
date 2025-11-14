/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:58:14 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include "parsing.h"

int	fill(t_cube *cube, int y, int x, int *n)
{
	if ((*n)++ >= MAP_SIZE || y < 0 || y >= cube->map->y_max || x < 0
		|| x >= (int)ft_strlen(cube->map->map[y]))
		return (1);
	if (cube->map->map[y][x] == '1' || cube->map->map[y][x] == 'O')
		return (0);
	if (cube->map->map[y][x] != '0' && cube->map->map[y][x] != 'S'
		&& cube->map->map[y][x] != 'N' && cube->map->map[y][x] != 'E'
		&& cube->map->map[y][x] != 'W')
		return (1);
	cube->map->map[y][x] = 'O';
	if (fill(cube, y + 1, x, n) == 1)
		return (1);
	if (fill(cube, y - 1, x, n) == 1)
		return (1);
	if (fill(cube, y, x - 1, n) == 1)
		return (1);
	if (fill(cube, y, x + 1, n) == 1)
		return (1);
	return (0);
}

int	flood_fill(t_cube *cube)
{
	int	x;
	int	y;
	int	n;

	n = 0;
	y = (int)cube->player->y / TILE;
	x = (int)cube->player->x / TILE;
	if (fill(cube, y, x, &n) == 1)
	{
		if (n >= MAP_SIZE)
		{
			ft_dprintf(2, "Error\nFlood_fill n > MAP_SIZE : %d\n",
				MAP_SIZE);
		}
		else
			ft_dprintf(2, "Error\nFlood_fill n = %d\n", n);
		return (1);
	}
	return (0);
}
