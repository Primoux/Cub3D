/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:57 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:59:29 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_management.h"
#include "parsing.h"

static int	init_texture(t_cube *cube, t_img *img, char *filename)
{
	char	*str;

	str = ft_strtrim(filename, " \t");
	if (!str)
		return (1);
	img->img = mlx_xpm_file_to_image(cube->mlx, str, &img->width, &img->height);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	if (!img->addr)
		return (1);
	return (0);
}

static int	init_display(t_cube *cube)
{
	if (init_texture(cube, cube->texture->n_wall, cube->map->n_wall_path) == 1)
		return (1);
	if (init_texture(cube, cube->texture->s_wall, cube->map->s_wall_path) == 1)
		return (1);
	if (init_texture(cube, cube->texture->e_wall, cube->map->e_wall_path) == 1)
		return (1);
	if (init_texture(cube, cube->texture->w_wall, cube->map->w_wall_path) == 1)
		return (1);
	cube->img->img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	if (!cube->img->img)
	{
		ft_dprintf(2, "Error\nmlx_new_image returned an error\n");
		return (2);
	}
	cube->img->addr = mlx_get_data_addr(cube->img->img, &cube->img->bpp,
			&cube->img->line_length, &cube->img->endian);
	if (!cube->img->addr)
	{
		ft_dprintf(2, "Error\nmlx_get_cube_addr returned an error\n");
		return (2);
	}
	return (0);
}

int	init_mlx(t_cube *cube)
{
	int	res;

	cube->mlx = mlx_init();
	if (!cube->mlx)
	{
		ft_dprintf(2, "Error\nmlx_init returned an error\n");
		return (1);
	}
	res = init_display(cube);
	if (res != 0)
	{
		if (res == 1)
			ft_dprintf(2, "Error\ninit_display returned an error\n");
		return (1);
	}
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, "Plein le CUB3D");
	if (!cube->win)
	{
		ft_dprintf(2, "Error\nmlx_new_window returned an error\n");
		return (1);
	}
	return (0);
}
