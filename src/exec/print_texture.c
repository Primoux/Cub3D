/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:52:47 by kapinarc          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include "raycast.h"
#include "utils.h"
#include <math.h>

static t_img	*texture_north_south(t_cube *cube, double *tex_x)
{
	*tex_x = fmod(cube->ray->hit_x, TILE);
	if (*tex_x < 0)
		*tex_x += TILE;
	*tex_x /= TILE;
	if (!ray_dir(cube->ray->angle, 0))
		return (cube->texture->n_wall);
	else
	{
		*tex_x = 1 - *tex_x;
		return (cube->texture->s_wall);
	}
}

static t_img	*texture_east_west(t_cube *cube, double *tex_x)
{
	*tex_x = fmod(cube->ray->hit_y, TILE);
	if (*tex_x < 0)
		*tex_x += TILE;
	*tex_x /= TILE;
	if (ray_dir(cube->ray->angle, 1))
		return (cube->texture->w_wall);
	else
	{
		*tex_x = 1 - *tex_x;
		return (cube->texture->e_wall);
	}
}

void	print_texture(t_cube *cube, int i, int j)
{
	double			tex_y;
	double			tex_x;
	unsigned int	color;
	t_img			*wall;

	if (cube->ray->flag == 'x')
		wall = texture_north_south(cube, &tex_x);
	else
		wall = texture_east_west(cube, &tex_x);
	tex_y = (double)((j - cube->ray->rwall_top) * wall->height
			/ cube->ray->rwall_height);
	color = *(unsigned int *)(wall->addr + ((int)tex_y * wall->line_length
				+ (int)(tex_x * wall->width) * (wall->bpp >> 3)));
	my_mlx_put_pixel(cube->img, i, j, color);
}
