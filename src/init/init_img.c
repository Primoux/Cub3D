/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:38:05 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/21 21:38:07 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_img(t_data *data)
{
	data->img = ft_calloc(1, sizeof(t_img));
	if (!data->img)
		return (1);
	return (0);
}
