/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:31 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 14:35:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_management.h"
#include "parsing.h"
#include <math.h>

static int	get_angle(t_data *data, char c, int y, int x)
{
	if (data->player->x || data->player->y)
		return (1);
	if (c == 'N')
		data->player->angle = 3 * M_PI_2;
	else if (c == 'S')
		data->player->angle = M_PI_2;
	else if (c == 'W')
		data->player->angle = M_PI;
	else
		data->player->angle = 0;
	data->player->x = x * TILE + TILE / 2;
	data->player->y = y * TILE + TILE / 2;
	return (0);
}

int	check_char(t_data *data, char **map, int *y, int *x)
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
				if (get_angle(data, map[*y][*x], *y, *x) == 1)
					return (2);
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}

int	check_map_validity(t_data *data, char **map)
{
	int	x;
	int	y;
	int	ret;

	ret = 0;
	x = 0;
	y = 0;
	ret = check_char(data, map, &y, &x);
	if (ret == 1)
	{
		ft_dprintf(2, "Error: wrong char in file y = %d x = %d char = %c\n", y,
			x, map[y][x]);
		return (1);
	}
	else if (ret == 2)
	{
		ft_dprintf(2, "Error: player character duplicated in map\n");
		return (1);
	}
	if (!data->player->x || !data->player->y)
	{
		ft_dprintf(2, "Error: no player character found in map\n");
		return (1);
	}
	return (0);
}
