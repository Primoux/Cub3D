/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_management.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:55:00 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/27 19:48:01 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MANAGEMENT_H
# define MLX_MANAGEMENT_H

# include "cub3d.h"

# define FOV 60
# define WIDTH 1280
# define HEIGHT 720
# define TILE 75
# define TEXTURE_RES 75
# define MOVE_SPEED 400
# define MOVE_SPRINT 800
# define ANGLE_MOUSE 0.0012
# define ANGLE_KEY 2
# define MOUSE_BUTTON_LEFT 1
# define MOUSE_BUTTON_RIGHT 3
# define TT_DESTROY 1.0
# define RANGE_DESTROY 3.0

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

void	winner(t_data *data);
void	draw_minimap(t_data *data);
void	my_mlx_put_pixel(t_img *img, int x, int y, int color);
int		handle_press_button(int button, int x, int y, t_data *data);
int		handle_release_button(int button, int x, int y, t_data *data);
void	handle_mouse_button(t_data *data, double current_time);

#endif