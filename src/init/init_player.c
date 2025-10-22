/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:47 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/22 18:27:45 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_player(t_data *data)
{
	data->player = ft_calloc(1, sizeof(t_player));
	if (!data->player)
		return (1);
	return (0);
}
