/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:25:18 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 14:25:19 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

int	close_window(t_data *data);
int	handle_press_key(int keycode, t_data *data);
int	handle_release_key(int keycode, t_data *data);
int	player_loop(t_data *data);
int	handle_press_button(int button, int x, int y, t_data *data);
int	handle_release_button(int button, int x, int y, t_data *data);

#endif