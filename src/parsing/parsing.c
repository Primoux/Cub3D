/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:49 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/18 17:32:34 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>
#include <unistd.h>

void	get_y_len(t_cube *cube)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < cube->map->y_max)
	{
		len = ft_strlen((cube->map->map[i]));
		if (len > cube->map->x_max)
			cube->map->x_max = len;
		i++;
	}
}

void	change_char(unsigned int i, char *str)
{
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '0')
			str[i] = 'O';
		i++;
	}
}

char	**copy_map(t_cube *cube)
{
	char	**map;
	int		y;
	int		i;

	map = ft_calloc(cube->map->y_max + 1, sizeof(char *));
	if (!map)
		return (free_tab_return_null(cube->map->map));
	y = -1;
	while (++y < cube->map->y_max)
	{
		map[y] = ft_calloc(cube->map->x_max + 1, sizeof(char));
		if (!map[y])
			return (free_tab_return_null(map));
		ft_memcpy(map[y], cube->map->map[y], ft_strlen(cube->map->map[y]));
		i = -1;
		while (++i < cube->map->x_max)
		{
			if (map[y][i] == ' ' || map[y][i] == '0' || map[y][i] == '\0')
				map[y][i] = 'O';
		}
		map[y][cube->map->x_max] = '\0';
	}
	map[y] = NULL;
	free_tab_return_null(cube->map->map);
	return (map);
}

int	parsing(t_cube *cube, char *argv)
{
	char	**map;

	cube->map->x_max = -1;
	if (check_name_and_access(cube, argv) == 1)
		return (1);
	cube->map->file_name = ft_strdup(argv);
	if (!cube->map->file_name)
		return (1);
	if (read_and_fill_map_informations(cube) == 1 || check_map_validity(cube,
			cube->map->map) == 1)
		return (1);
	get_y_len(cube);
	if (flood_fill(cube) == 1)
		return (1);
	map = copy_map(cube);
	if (!map)
		return (1);
	cube->map->map = map;
	return (EXIT_SUCCESS);
}
