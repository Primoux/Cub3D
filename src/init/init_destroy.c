/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:42 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/29 15:14:36 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_destroy(t_data *data)
{
	data->destroy = ft_calloc(1, sizeof(t_destroy));
	if (!data->destroy)
		return (1);
	data->destroy->begin_destroy = -1.0;
	data->destroy->destroy_x = -1;
	data->destroy->destroy_y = -1;
	return (0);
}
