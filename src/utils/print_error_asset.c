/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_asset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:36:59 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/21 21:37:01 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error_asset(t_data *data)
{
	if (!data->map->n_wall_path)
		ft_dprintf(2, "Error: missing north wall texture (NO)\n");
	if (!data->map->s_wall_path)
		ft_dprintf(2, "Error: missing south wall texture (SO)\n");
	if (!data->map->w_wall_path)
		ft_dprintf(2, "Error: missing west wall texture (WE)\n");
	if (!data->map->e_wall_path)
		ft_dprintf(2, "Error: missing east wall texture (EA)\n");
	if (!data->map->floor_color)
		ft_dprintf(2, "Error: missing floor color (F)\n");
	if (!data->map->ceiling_color)
		ft_dprintf(2, "Error: missing ceiling color (C)\n");
}
