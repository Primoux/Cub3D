/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:57 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/25 16:24:34 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_management.h"
#include "parsing.h"
#include "utils.h"

static int	init_texture(t_cube *cube, t_img *img, char *filename)
{
	char	*str;

	str = ft_strtrim(filename, " \t");
	if (!str)
		return (print_error("ft_strtrim failed\n\
str is null", __FILE__, __LINE__, RETURN_1));
	img->img = mlx_xpm_file_to_image(cube->mlx, str, &img->width, &img->height);
	free(str);
	if (!img->img)
		return (print_error("mlx_xpm_file_to_image failed\n\
Unable to setup the image", __FILE__, __LINE__, RETURN_1));
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	if (!img->addr)
		return (print_error("mlx_get_data_addr failed\n\
Unable to setup the image informations", __FILE__, __LINE__, RETURN_1));
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
		return (print_error("mlx_new_image failed\n\
cube->img->img is NULL", __FILE__, __LINE__, RETURN_1));
	cube->img->addr = mlx_get_data_addr(cube->img->img, &cube->img->bpp,
			&cube->img->line_length, &cube->img->endian);
	if (!cube->img->addr)
		return (print_error("mlx_get_data_addr failed\n\
Unable to setup the address of the image", __FILE__, __LINE__, RETURN_1));
	return (0);
}

int	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init();
	if (!cube->mlx)
		return (print_error("mlx_init failed\n\
Unable to setup the mlx", __FILE__, __LINE__, RETURN_1));
	if (init_display(cube) == 1)
		return (1);
	cube->win = mlx_new_window(cube->mlx, WIDTH, HEIGHT, "Plein le CUB3D");
	if (!cube->win)
		return (print_error("mlx_new_window failed\n\
Unable to setup the window", __FILE__, __LINE__, RETURN_1));
	return (0);
}
