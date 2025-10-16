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
		// if (data->texture->wall && data->mlx)
		// 	mlx_destroy_image(data->mlx, data->texture->wall);
		// if (data->texture->perso_n && data->mlx)
		// 	mlx_destroy_image(data->mlx, data->texture->perso_n);
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
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_images(data);
	free_structs(data);
	free_mlx(data);
}
