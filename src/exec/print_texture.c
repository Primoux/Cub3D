/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:52:47 by kapinarc          #+#    #+#             */
/*   Updated: 2025/10/22 17:09:04 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"

static t_img	*texture_north_south(t_data *data, double *tex_x)
{
	*tex_x = fmod(data->ray->hit_x, TILE);
	if (*tex_x < 0)
		*tex_x += TILE;
	*tex_x /= TILE;
	if (!ray_dir(data->ray->angle, 0))
	{
		return (data->texture->n_wall);
	}
	else
	{
		*tex_x = 1 - *tex_x;
		return (data->texture->s_wall);
	}
}

static t_img	*texture_east_west(t_data *data, double *tex_x)
{
	*tex_x = fmod(data->ray->hit_y, TILE);
	if (*tex_x < 0)
		*tex_x += TILE;
	*tex_x /= TILE;
	if (ray_dir(data->ray->angle, 1))
	{
		return (data->texture->w_wall);
	}
	else
	{
		*tex_x = 1 - *tex_x;
		return (data->texture->e_wall);
	}
}

void	print_reticle(t_data *data)
{
	int x;
	int y;
	int max_x;
	int max_y;
	int	lenght;

	lenght = 10;
	x = (WIDTH >> 1) - lenght;
	y = (HEIGHT >> 1) - lenght;
	max_x = (WIDTH >> 1) + lenght;
	max_y = (HEIGHT >> 1) + lenght;

	while (x <= max_x)
	{
		my_mlx_put_pixel(data->img, x, (HEIGHT >> 1), 0x0FF0000);
		x++;
	}
	while (y<= max_y)
	{
		my_mlx_put_pixel(data->img, (WIDTH >> 1), y, 0x0FF0000);
		y++;
	}
}

void	print_texture(t_data *data, int i, int j)
{
	double			tex_y;
	double			tex_x;
	unsigned int	color;
	t_img			*wall;

	if (data->ray->flag == 'x')
		wall = texture_north_south(data, &tex_x);
	else
		wall = texture_east_west(data, &tex_x);
	tex_y = (double)((j - data->ray->rwall_top) * wall->height
			/ data->ray->rwall_height);
	color = *(unsigned int *)(wall->addr + ((int)tex_y * wall->line_length
				+ (int)(tex_x * wall->width) * (wall->bpp / 8)));
	my_mlx_put_pixel(data->img, i, j, color);
}
