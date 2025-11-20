/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:58:14 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/20 13:03:13 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include "parsing.h"
#include "utils.h"

int	flood_fill(t_cube *cube, int y, int x, int *n)
{
	if ((*n)++ >= MAX_MAP_SIZE || y < 0 || y >= cube->map->y_max || x < 0
		|| x >= (int)ft_strlen(cube->map->map[y]))
		return (1);
	if (cube->map->map[y][x] == '1' || cube->map->map[y][x] == 'O')
		return (0);
	if (cube->map->map[y][x] != '0' && cube->map->map[y][x] != 'S'
		&& cube->map->map[y][x] != 'N' && cube->map->map[y][x] != 'E'
		&& cube->map->map[y][x] != 'W')
		return (1);
	cube->map->map[y][x] = 'O';
	if (flood_fill(cube, y + 1, x, n) == 1)
		return (1);
	if (flood_fill(cube, y - 1, x, n) == 1)
		return (1);
	if (flood_fill(cube, y, x - 1, n) == 1)
		return (1);
	if (flood_fill(cube, y, x + 1, n) == 1)
		return (1);
	return (0);
}

int	launch_flood_fill(t_cube *cube)
{
	int	x;
	int	y;
	int	n;

	n = 0;
	y = (int)cube->player->y / TILE;
	x = (int)cube->player->x / TILE;
	if (flood_fill(cube, y, x, &n) == 1)
	{
		if (n >= MAX_MAP_SIZE)
			return (print_error("flood_fill failed\n\
Number of call exeeded MAX_MAP_SIZE", __FILE__, __LINE__, RETURN_1));
		else
			return (print_error("flood_fill failed\n\
Map is not close from the player position", __FILE__, __LINE__, RETURN_1));
	}
	return (0);
}
