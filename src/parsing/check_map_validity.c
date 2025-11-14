/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:31 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_management.h"
#include "parsing.h"
#include <math.h>

static int	get_angle(t_cube *cube, char c, int y, int x)
{
	if (cube->player->x || cube->player->y)
		return (1);
	if (c == 'N')
		cube->player->angle = 3 * M_PI_2;
	else if (c == 'S')
		cube->player->angle = M_PI_2;
	else if (c == 'W')
		cube->player->angle = M_PI;
	else
		cube->player->angle = 0;
	cube->player->x = x * TILE + (TILE >> 1);
	cube->player->y = y * TILE + (TILE >> 1);
	return (0);
}

int	check_char(t_cube *cube, char **map, int *y, int *x)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (char_compare(map[*y][*x]) == 1)
				return (1);
			if (map[*y][*x] == 'N' || map[*y][*x] == 'S' || map[*y][*x] == 'W'
				|| map[*y][*x] == 'E')
				if (get_angle(cube, map[*y][*x], *y, *x) == 1)
					return (2);
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}

int	check_map_validity(t_cube *cube, char **map)
{
	int	x;
	int	y;
	int	ret;

	ret = 0;
	x = 0;
	y = 0;
	ret = check_char(cube, map, &y, &x);
	if (ret == 1)
	{
		ft_dprintf(2, "Error\nWrong char in file char\n");
		return (1);
	}
	else if (ret == 2)
	{
		ft_dprintf(2, "Error\nPlayer character duplicated in map\n");
		return (1);
	}
	if (!cube->player->x || !cube->player->y)
	{
		ft_dprintf(2, "Error\nNo player character found in map\n");
		return (1);
	}
	return (0);
}
