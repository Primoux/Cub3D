/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:24:45 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:55:14 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

double	get_time_to_msec(void);
void	my_mlx_put_pixel(t_img *img, int x, int y, int color);
void	print_error_asset(t_cube *cube);
void	print_map_and_params(t_cube *cube);
void	winner(t_cube *cube);
void	handle_mouse_button(t_cube *cube, double current_time);

#endif