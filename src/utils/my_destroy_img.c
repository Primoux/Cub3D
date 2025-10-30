/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_destroy_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:27:54 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 14:40:03 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "memory.h"
#include <mlx.h>

void	my_destroy_img(t_mlx *mlx, t_img *img)
{
	if (img)
	{
		if (img->img && mlx)
			mlx_destroy_image(mlx, img->img);
		free(img);
	}
}
