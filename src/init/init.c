/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:39 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/22 18:50:27 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	init(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	if (init_player(data) != 0)
		return (1);
	if (init_map(data) != 0)
		return (1);
	if (init_texture(data) != 0)
		return (1);
	if (init_ray(data) != 0)
		return (1);
	if (init_img(data) != 0)
		return (1);
	if (init_keys(data) != 0)
		return (1);
	return (0);
}
