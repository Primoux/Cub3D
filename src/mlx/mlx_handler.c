/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:55:40 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include "game.h"

void	winner(t_cube *cube)
{
	mlx_hook(cube->win, 2, 1L << 0, handle_press_key, cube);
	mlx_hook(cube->win, 3, 1L << 1, handle_release_key, cube);
	mlx_hook(cube->win, 4, 1L << 2, handle_press_button, cube);
	mlx_hook(cube->win, 5, 1L << 3, handle_release_button, cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img->img, 0, 0);
	mlx_hook(cube->win, 17, 0, close_window, cube);
	mlx_loop_hook(cube->mlx, &player_loop, cube);
	mlx_loop(cube->mlx);
}
