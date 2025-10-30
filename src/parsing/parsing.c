/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:49 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 11:03:27 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>
#include <unistd.h>

void	get_y_len(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < data->map->y_max)
	{
		len = ft_strlen((data->map->map[i]));
		if (len > data->map->x_max)
			data->map->x_max = len;
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

char	**copy_map(t_data *data)
{
	char	**map;
	int		y;
	int		i;

	map = ft_calloc(data->map->y_max + 1, sizeof(char *));
	if (!map)
		return (NULL);
	y = -1;
	while (++y < data->map->y_max)
	{
		map[y] = ft_calloc(data->map->x_max + 1, sizeof(char));
		if (!map[y])
			return (free_tab_return_null(map));
		ft_memcpy(map[y], data->map->map[y], ft_strlen(data->map->map[y]));
		i = -1;
		while (++i < data->map->x_max)
		{
			if (map[y][i] == ' ' || map[y][i] == '0' || map[y][i] == '\0')
				map[y][i] = 'O';
		}
		map[y][data->map->x_max] = '\0';
	}
	map[y] = NULL;
	free_tab_return_null(data->map->map);
	return (map);
}

int	parsing(t_data *data, char *argv)
{
	data->map->x_max = -1;
	if (check_name_and_access(data, argv) == 1)
		return (1);
	data->map->file_name = ft_strdup(argv);
	if (!data->map->file_name)
		return (1);
	if (read_and_fill_map_informations(data) == 1 || check_map_validity(data,
			data->map->map) == 1)
		return (1);
	get_y_len(data);
	if (flood_fill(data) == 1)
		return (1);
	data->map->map = copy_map(data);
	if (!data->map->map)
		return (1);
	return (EXIT_SUCCESS);
}
