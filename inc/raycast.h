/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:23:00 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:55:14 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

void	norm_angle(double *angle);
int		ray_dir(double angle, int mode);
int		is_wall(t_map *map, double x, double y);
int		balance_inter(double angle, double *inter, double *step, int mode);
void	raycast_loop(t_cube *cube);
double	lazerizor(t_cube *cube, double angle);
void	print_texture(t_cube *cube, int i, int j);

#endif
