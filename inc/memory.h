/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:25:16 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:55:14 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include "cub3d.h"

void	free_all(t_cube *cube);
void	free_mlx(t_cube *cube);
void	free_structs(t_cube *cube);
void	free_images(t_cube *cube);
void	my_destroy_img(t_mlx *mlx, t_img *img);
void	free_map(t_map *map);

#endif