/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:57 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/27 19:43:00 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_management.h"
#include "parsing.h"

static int	init_texture(t_data *data, t_img *img, char *filename)
{
	img->img = mlx_xpm_file_to_image(data->mlx, filename, &img->width,
			&img->height);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	if (!img->addr)
		return (1);
	return (0);
}

static int	init_display(t_data *data)
{
	if (init_texture(data, data->texture->n_wall, data->map->n_wall_path) == 1)
		return (1);
	if (init_texture(data, data->texture->s_wall, data->map->s_wall_path) == 1)
		return (1);
	if (init_texture(data, data->texture->e_wall, data->map->e_wall_path) == 1)
		return (1);
	if (init_texture(data, data->texture->w_wall, data->map->w_wall_path) == 1)
		return (1);
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img->img)
	{
		ft_dprintf(2, "Error: mlx_new_image failed in %s line %d\n", __FILE__,
			__LINE__);
		return (2);
	}
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->line_length, &data->img->endian);
	if (!data->img->addr)
	{
		ft_dprintf(2, "Error: mlx_get_data_addr failed in %s line %d\n",
			__FILE__, __LINE__);
		return (2);
	}
	return (0);
}

int	init_mlx(t_data *data)
{
	int	res;

	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_dprintf(2, "Error: mlx_init failed in %s line %d\n", __FILE__,
			__LINE__);
		return (1);
	}
	res = init_display(data);
	if (res != 0)
	{
		if (res == 1)
			ft_dprintf(2, "Error: Invalid texture path in %s line %d\n",
				__FILE__, __LINE__);
		return (1);
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Plein le CUB3D");
	if (!data->win)
	{
		ft_dprintf(2, "Error: mlx_new_window failed in %s line %d\n", __FILE__,
			__LINE__);
		return (1);
	}
	return (0);
}
