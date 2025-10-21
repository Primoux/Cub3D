/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:38:08 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/21 21:40:50 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"

int	init_base(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->mlx = NULL;
	data->player = ft_calloc(1, sizeof(t_player));
	if (!data->player)
		return (1);
	if (init_player(data->player) != 0)
		return (1);
	return (0);
}
