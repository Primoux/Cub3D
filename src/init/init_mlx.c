/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:57 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/21 21:50:20 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_management.h"
#include "parsing.h"

static int	init_texture(t_data *data, t_img *img)
{
	img->img = mlx_xpm_file_to_image(data->mlx, data->map->n_wall_path,
			&img->width, &img->height);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	if (!img->addr)
		return (1);
	return (0);
}

static int	init_img(t_data *data)
{
	if (init_texture(data, data->texture->n_wall) == 1)
		return (1);
	if (init_texture(data, data->texture->s_wall) == 1)
		return (1);
	if (init_texture(data, data->texture->e_wall) == 1)
		return (1);
	if (init_texture(data, data->texture->w_wall) == 1)
		return (1);
	if (init_texture(data, data->img) == 1)
		return (1);
	return (0);
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_dprintf(2, "Error: mlx_init failed in %s line %d\n",
				__FILE__, __LINE__));
	if (init_img(data) == 1)
		return (ft_dprintf(2, "Error: Invalid texture path in %s line %d\n",
				__FILE__, __LINE__));
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "prout");
	if (!data->win)
		return (ft_dprintf(2, "Error: mlx_new_window failed in %s line %d\n",
				__FILE__, __LINE__));
	return (0);
}
