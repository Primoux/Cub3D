#include "cub3d.h"

/*
 * Initialize the t_data structure and allocate sub-structures.
 * This function keeps the same signature (void) to match the
 * existing header, but it will log allocation failures to stderr.
 */
void	init(t_data *data)
{
	ft_bzero(data, sizeof(*data));

	/* basic pointers */
	data->mlx = NULL;
	data->win = NULL;

	/* allocate and initialize map structure */
	data->map = malloc(sizeof(*(data->map)));
	if (data->map)
	{
		data->map->file_name = NULL;
		data->map->map = NULL;
		data->map->n_wall_path = NULL;
		data->map->s_wall_path = NULL;
		data->map->e_wall_path = NULL;
		data->map->w_wall_path = NULL;
		data->map->floor_color = NULL;
		data->map->sky_color = NULL;
	}
	else
	{
		ft_putstr_fd("init: failed to allocate map\n", 2);
	}

	/* allocate and initialize image structure */
	data->img = malloc(sizeof(*(data->img)));
	if (data->img)
	{
		data->img->floor = NULL;
		data->img->wall = NULL;
	}
	else
	{
		ft_putstr_fd("init: failed to allocate img\n", 2);
	}
}