/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:42 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/25 16:02:08 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

int	init_texture(t_cube *cube)
{
	cube->texture = ft_calloc(1, sizeof(t_texture));
	if (!cube->texture)
		return (print_error("ft_calloc failed", __FILE__, __LINE__, RETURN_1));
	cube->texture->n_wall = ft_calloc(1, sizeof(t_img));
	if (!cube->texture->n_wall)
		return (print_error("ft_calloc failed", __FILE__, __LINE__, RETURN_1));
	cube->texture->s_wall = ft_calloc(1, sizeof(t_img));
	if (!cube->texture->s_wall)
		return (print_error("ft_calloc failed", __FILE__, __LINE__, RETURN_1));
	cube->texture->e_wall = ft_calloc(1, sizeof(t_img));
	if (!cube->texture->e_wall)
		return (print_error("ft_calloc failed", __FILE__, __LINE__, RETURN_1));
	cube->texture->w_wall = ft_calloc(1, sizeof(t_img));
	if (!cube->texture->w_wall)
		return (print_error("ft_calloc failed", __FILE__, __LINE__, RETURN_1));
	return (0);
}
