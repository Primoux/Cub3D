/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:54:46 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:55:14 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

int	init(t_cube *cube);
int	init_colors(t_cube *cube);
int	init_player(t_cube *cube);
int	init_map(t_cube *cube);
int	init_mlx(t_cube *cube);
int	init_texture(t_cube *cube);
int	init_ray(t_cube *cube);
int	init_img(t_cube *cube);
int	init_keys(t_cube *cube);
int	init_destroy(t_cube *cube);

#endif
