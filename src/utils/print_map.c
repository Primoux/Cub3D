/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:53:27 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_and_params(t_cube *cube)
{
	int	i;

	ft_printf("%s\n", cube->map->n_wall_path);
	ft_printf("%s\n", cube->map->s_wall_path);
	ft_printf("%s\n", cube->map->w_wall_path);
	ft_printf("%s\n", cube->map->e_wall_path);
	ft_printf("%s\n", cube->map->ceiling_color);
	ft_printf("%s\n", cube->map->floor_color);
	i = 0;
	while (cube->map->map[i])
	{
		ft_printf("%s\n", cube->map->map[i]);
		i++;
	}
	ft_printf("y_max = %d\nx_max = %d\n", cube->map->y_max, cube->map->x_max);
}
