/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:47 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/21 21:37:48 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_player(t_player *player)
{
	if (!player)
		return (1);
	player->px = 0;
	player->py = 0;
	player->angle = 0;
	return (0);
}
