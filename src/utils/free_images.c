/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:28:11 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/25 16:08:03 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "memory.h"

void	free_images(t_cube *cube)
{
	my_destroy_img(cube->mlx, cube->img);
	if (cube->texture)
	{
		my_destroy_img(cube->mlx, cube->texture->n_wall);
		my_destroy_img(cube->mlx, cube->texture->s_wall);
		my_destroy_img(cube->mlx, cube->texture->e_wall);
		my_destroy_img(cube->mlx, cube->texture->w_wall);
	}
}
