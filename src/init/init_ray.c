/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:44 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/22 18:28:56 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_ray(t_data *data)
{
	data->ray = ft_calloc(1, sizeof(t_ray));
	if (!data->ray)
		return (1);
	return (0);
}
