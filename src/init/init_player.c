/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:47 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/25 16:01:01 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

int	init_player(t_cube *cube)
{
	cube->player = ft_calloc(1, sizeof(t_player));
	if (!cube->player)
		return (print_error("ft_calloc failed", __FILE__, __LINE__, RETURN_1));
	return (0);
}
