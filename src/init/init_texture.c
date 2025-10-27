/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:42 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/22 18:28:47 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_texture(t_data *data)
{
	data->texture = ft_calloc(1, sizeof(t_texture));
	if (!data->texture)
		return (1);
	data->texture->n_wall = ft_calloc(1, sizeof(t_img));
	if (!data->texture->n_wall)
		return (1);
	data->texture->s_wall = ft_calloc(1, sizeof(t_img));
	if (!data->texture->s_wall)
		return (1);
	data->texture->e_wall = ft_calloc(1, sizeof(t_img));
	if (!data->texture->e_wall)
		return (1);
	data->texture->w_wall = ft_calloc(1, sizeof(t_img));
	if (!data->texture->w_wall)
		return (1);
	data->texture->w_wall = ft_calloc(1, sizeof(t_img));
	if (!data->texture->w_wall)
		return (1);
	data->texture->w_wall = ft_calloc(1, sizeof(t_img));
	if (!data->texture->w_wall)
		return (1);
	data->texture->destroy_1 = ft_calloc(1, sizeof(t_img));
	if (!data->texture->destroy_1)
		return (1);
	data->texture->destroy_2 = ft_calloc(1, sizeof(t_img));
	if (!data->texture->destroy_2)
		return (1);
	data->texture->destroy_3 = ft_calloc(1, sizeof(t_img));
	if (!data->texture->destroy_3)
		return (1);
	data->texture->destroy_4 = ft_calloc(1, sizeof(t_img));
	if (!data->texture->destroy_4)
		return (1);
	return (0);
}
