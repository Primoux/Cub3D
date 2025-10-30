/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:44 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 14:34:45 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include <math.h>

int	init_ray(t_data *data)
{
	data->ray = ft_calloc(1, sizeof(t_ray));
	if (!data->ray)
		return (1);
	data->ray->rad_fov = FOV * (M_PI / 180);
	data->ray->ratio = (2 * tan(data->ray->rad_fov / 2)) / WIDTH;
	return (0);
}
