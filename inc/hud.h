/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:23:01 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 14:32:21 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include "cub3d.h"

void	display_hud(t_data *data, double current_time);
void	draw_infos(t_data *data, double current_time_s);
void	draw_fps(t_data *data, double current_time_ms);
void	draw_minimap(t_data *data);
void	print_reticle(t_data *data);

#endif