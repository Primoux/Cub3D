/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_asset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:36:59 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error_asset(t_cube *cube)
{
	if (!cube->map->n_wall_path)
		ft_dprintf(2, "Error\nMissing north wall texture (NO)\n");
	if (!cube->map->s_wall_path)
		ft_dprintf(2, "Error\nMissing south wall texture (SO)\n");
	if (!cube->map->w_wall_path)
		ft_dprintf(2, "Error\nMissing west wall texture (WE)\n");
	if (!cube->map->e_wall_path)
		ft_dprintf(2, "Error\nMissing east wall texture (EA)\n");
	if (!cube->map->floor_color)
		ft_dprintf(2, "Error\nMissing floor color (F)\n");
	if (!cube->map->ceiling_color)
		ft_dprintf(2, "Error\nMissing ceiling color (C)\n");
}
