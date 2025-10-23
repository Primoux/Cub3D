/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:27:45 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/23 19:30:39 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_structs(t_data *data)
{
	if (data->player)
		free(data->player);
	if (data->ray)
		free(data->ray);
	if (data->key)
		free(data->key);
	if (data->texture)
		free(data->texture);
	if (data->map)
		free_map(data->map);
}
