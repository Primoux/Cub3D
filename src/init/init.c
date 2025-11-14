/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:39 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	init(t_cube *cube)
{
	ft_bzero(cube, sizeof(t_cube));
	if (init_player(cube) != 0)
		return (1);
	if (init_map(cube) != 0)
		return (1);
	if (init_texture(cube) != 0)
		return (1);
	if (init_ray(cube) != 0)
		return (1);
	if (init_img(cube) != 0)
		return (1);
	if (init_keys(cube) != 0)
		return (1);
	if (init_destroy(cube) != 0)
		return (1);
	return (0);
}
