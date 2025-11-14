/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:27:45 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "memory.h"

void	free_structs(t_cube *cube)
{
	if (cube->player)
		free(cube->player);
	if (cube->ray)
		free(cube->ray);
	if (cube->key)
		free(cube->key);
	if (cube->texture)
		free(cube->texture);
	if (cube->destroy)
		free(cube->destroy);
	if (cube->map)
		free_map(cube->map);
}
