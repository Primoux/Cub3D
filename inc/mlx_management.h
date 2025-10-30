/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_management.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:55:00 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 14:35:06 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MANAGEMENT_H
# define MLX_MANAGEMENT_H

#include "mlx.h"

# define FOV 60
# define WIDTH 1280
# define HEIGHT 720
# define TILE 75
# define MOVE_SPEED 400
# define MOVE_SPRINT 800
# define ANGLE_MOUSE 0.0012f
# define ANGLE_KEY 2.0f
# define MOUSE_BUTTON_LEFT 1
# define MOUSE_BUTTON_RIGHT 3
# define TT_DESTROY 2.0f
# define RANGE_DESTROY 3.0f

typedef enum e_mod_key
{
	HOLD_MOD,
	PRESS_MOD
}		t_mod_key;

typedef enum e_key_action
{
	PRESS_ACTION,
	RELEASE_ACTION
}		t_key_action;


#endif