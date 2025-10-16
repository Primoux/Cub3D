#include "mlx_management.h"
#include "parsing.h"

static int	stock_xpm(t_data *data)
{
	int	width;
	int	height;

	width = TEXTURE_RES;
	height = TEXTURE_RES;
	data->texture->n_wall = mlx_xpm_file_to_image(data->mlx,
			data->map->n_wall_path, &width, &height);
	if (!data->texture->n_wall)
		return (1);
	data->texture->s_wall = mlx_xpm_file_to_image(data->mlx,
			data->map->s_wall_path, &width, &height);
	if (!data->texture->s_wall)
		return (1);
	data->texture->e_wall = mlx_xpm_file_to_image(data->mlx,
			data->map->e_wall_path, &width, &height);
	if (!data->texture->e_wall)
		return (1);
	data->texture->w_wall = mlx_xpm_file_to_image(data->mlx,
			data->map->w_wall_path, &width, &height);
	if (!data->texture->w_wall)
		return (1);
	return (0);
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_dprintf(2, "Error: mlx_init failed\n");
		return (1);
	}
	if (stock_xpm(data) == 1)
	{
		ft_dprintf(2, "Error: Invalid texture path\n");
		return (1);
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "prout");
	if (!data->win)
	{
		ft_dprintf(2, "Error: mlx_new_window failed\n");
		return (1);
	}
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->line_length, &data->img->endian);
	return (0);
}
