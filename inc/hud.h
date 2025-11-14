/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:23:01 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:55:14 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include "cub3d.h"

void	display_hud(t_cube *cube, double current_time);
void	draw_infos(t_cube *cube, double current_time_s);
void	draw_fps(t_cube *cube, double current_time_ms);
void	draw_minimap(t_cube *cube);
void	print_reticle(t_cube *cube);
void	draw_key_state(t_cube *cube, int x, bool is_pressed, const char *key);
#endif