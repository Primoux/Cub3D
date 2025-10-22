/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:53:31 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/22 18:34:06 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->fd_map >= 0)
		safe_close(&map->fd_map);
	free(map->file_name);
	free(map->n_wall_path);
	free(map->s_wall_path);
	free(map->w_wall_path);
	free(map->e_wall_path);
	free(map->floor_color);
	free(map->ceiling_color);
	if (map->map)
		free_tab_return_null(map->map);
	free(map);
}

static void	free_images(t_data *data)
{
	if (data->img)
	{
		if (data->img->img && data->mlx)
			mlx_destroy_image(data->mlx, data->img->img);
		free(data->img);
	}
	if (data->texture)
	{
		if (data->texture->n_wall)
		{
			if (data->texture->n_wall->img)
				mlx_destroy_image(data->mlx, data->texture->n_wall->img);
			free(data->texture->n_wall);
		}
		if (data->texture->s_wall)
		{
			if (data->texture->s_wall->img)
				mlx_destroy_image(data->mlx, data->texture->s_wall->img);
			free(data->texture->s_wall);
		}
		if (data->texture->e_wall)
		{
			if (data->texture->e_wall->img)
				mlx_destroy_image(data->mlx, data->texture->e_wall->img);
			free(data->texture->e_wall);
		}
		if (data->texture->w_wall)
		{
			if (data->texture->w_wall->img)
				mlx_destroy_image(data->mlx, data->texture->w_wall->img);
			free(data->texture->w_wall);
		}
		free(data->texture);
	}
}

static void	free_structs(t_data *data)
{
	if (data->player)
		free(data->player);
	if (data->ray)
		free(data->ray);
	if (data->key)
		free(data->key);
	if (data->map)
		free_map(data->map);
}

static void	free_mlx(t_data *data)
{

	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_images(data);
	free_structs(data);
	free_mlx(data);
}
