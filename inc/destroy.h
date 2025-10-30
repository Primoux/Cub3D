/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:22:58 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 14:23:00 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTROY_H
# define DESTROY_H

# include "cub3d.h"

void	stock_block(t_data *data);
void	raycast_to_pointed_block(t_data *data);
void	destroy_bar(t_data *data, char state);
void	destroy_block(t_data *data, int tile_x, int tile_y,
			double current_time);

#endif