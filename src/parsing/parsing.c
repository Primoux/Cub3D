/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:49 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/21 22:26:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdlib.h>
#include <unistd.h>

int	parsing(t_data *data, char *argv)
{
	int	i;
	int	len;

	data->map->x_max = -1;
	if (check_name_and_access(data, argv) == 1)
		return (1);
	data->map->file_name = ft_strdup(argv);
	if (!data->map->file_name)
		return (1);
	if (read_and_fill_map_informations(data) == 1 || check_map_validity(data,
			data->map->map) == 1)
		return (1);
	i = 0;
	while (i < data->map->y_max)
	{
		len = ft_strlen((data->map->map[i]));
		if (len > data->map->x_max)
			data->map->x_max = len - 1;
		i++;
	}
	if (flood_fill(data) == 1)
		return (1);
	return (EXIT_SUCCESS);
}
