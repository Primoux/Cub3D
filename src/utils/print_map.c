/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:53:27 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/22 16:36:15 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_and_params(t_data *data)
{
	int	i;

	ft_printf("%s\n", data->map->n_wall_path);
	ft_printf("%s\n", data->map->s_wall_path);
	ft_printf("%s\n", data->map->w_wall_path);
	ft_printf("%s\n", data->map->e_wall_path);
	ft_printf("%s\n", data->map->ceiling_color);
	ft_printf("%s\n", data->map->floor_color);
	i = 0;
	while (data->map->map[i])
	{
		ft_printf("%s\n", data->map->map[i]);
		i++;
	}
	ft_printf("y_max = %d\nx_max = %d\n", data->map->y_max, data->map->x_max);
}
