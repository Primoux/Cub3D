/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:24:45 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/20 13:02:10 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

# define ERROR_MSG "Error\n"
# define RETURN_1 1
# define RETURN_2 2

double	get_time_to_msec(void);
void	my_mlx_put_pixel(t_img *img, int x, int y, int color);
void	print_map_and_params(t_cube *cube);
void	windowser(t_cube *cube);
void	handle_mouse_button(t_cube *cube, double current_time);
int		print_error(char *str, char *file, int line, int ret);

#endif