/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_management.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:55:00 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/22 19:38:01 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MANAGEMENT_H
# define MLX_MANAGEMENT_H

# include "cub3d.h"

# define TILE 75
# define TEXTURE_RES 75
# define MOVE_SPEED 500
# define MOVE_SPRINT 750
# define ANGLE_SPEED 5

typedef enum
{
	HOLD_MOD,
	PRESS_MOD
}		t_mod_key;

typedef enum
{
	PRESS_ACTION,
	RELEASE_ACTION
}		t_key_action;

void	winner(t_data *data);
void	draw_minimap(t_data *data);
void	my_mlx_put_pixel(t_img *img, int x, int y, int color);

#endif