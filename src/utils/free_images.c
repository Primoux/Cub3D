/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:28:11 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 14:39:18 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "memory.h"

void	free_images(t_data *data)
{
	my_destroy_img(data->mlx, data->img);
	my_destroy_img(data->mlx, data->texture->n_wall);
	my_destroy_img(data->mlx, data->texture->s_wall);
	my_destroy_img(data->mlx, data->texture->e_wall);
	my_destroy_img(data->mlx, data->texture->w_wall);
}
