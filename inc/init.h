/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:54:46 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/21 22:20:34 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

int	init(t_data *data);
int	init_colors(t_data *data);
int	init(t_data *data);
int	init_base(t_data *data);
int	init_player(t_player *player);
int	init_map(t_data *data);
int	init_mlx(t_data *data);
int	init_texture(t_data *data);
int	init_ray(t_data *data);
int	init_img(t_data *data);
int	init_keys(t_data *data);

#endif
