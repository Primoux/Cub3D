/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:44 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/25 16:09:40 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include "utils.h"
#include <math.h>

int	init_ray(t_cube *cube)
{
	cube->ray = ft_calloc(1, sizeof(t_ray));
	if (!cube->ray)
		return (print_error("ft_calloc failed", __FILE__, __LINE__, RETURN_1));
	cube->ray->rad_fov = FOV * (M_PI / 180);
	cube->ray->ratio = (2 * tan(cube->ray->rad_fov / 2)) / WIDTH;
	return (0);
}
