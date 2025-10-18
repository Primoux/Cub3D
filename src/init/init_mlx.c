#include "mlx_management.h"
#include "parsing.h"

static int	stock_xpm(t_data *data)
{
	data->texture->n_wall->img = mlx_xpm_file_to_image(data->mlx,
			data->map->n_wall_path, &data->texture->n_wall->width,
			&data->texture->n_wall->height);
	if (!data->texture->n_wall->img)
		return (1);
	data->texture->n_wall->addr = mlx_get_data_addr(data->texture->n_wall->img,
			&data->texture->n_wall->bpp, &data->texture->n_wall->line_length,
			&data->texture->n_wall->endian);
	if (!data->texture->n_wall->addr)
		return (1);
	data->texture->s_wall->img = mlx_xpm_file_to_image(data->mlx,
			data->map->s_wall_path, &data->texture->s_wall->width,
			&data->texture->s_wall->height);
	if (!data->texture->s_wall->img)
		return (1);
	data->texture->s_wall->addr = mlx_get_data_addr(data->texture->s_wall->img,
			&data->texture->s_wall->bpp, &data->texture->s_wall->line_length,
			&data->texture->s_wall->endian);
	if (!data->texture->s_wall->addr)
		return (1);
	data->texture->e_wall->img = mlx_xpm_file_to_image(data->mlx,
			data->map->e_wall_path, &data->texture->e_wall->width,
			&data->texture->e_wall->height);
	if (!data->texture->e_wall->img)
		return (1);
	data->texture->e_wall->addr = mlx_get_data_addr(data->texture->e_wall->img,
			&data->texture->e_wall->bpp, &data->texture->e_wall->line_length,
			&data->texture->e_wall->endian);
	if (!data->texture->e_wall->addr)
		return (1);
	data->texture->w_wall->img = mlx_xpm_file_to_image(data->mlx,
			data->map->w_wall_path, &data->texture->w_wall->width,
			&data->texture->w_wall->height);
	if (!data->texture->w_wall->img)
		return (1);
	data->texture->w_wall->addr = mlx_get_data_addr(data->texture->w_wall->img,
			&data->texture->w_wall->bpp, &data->texture->w_wall->line_length,
			&data->texture->w_wall->endian);
	if (!data->texture->w_wall->addr)
		return (1);
	return (0);
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_dprintf(2, "Error: mlx_init failed in %s line %d\n",
				__FILE__, __LINE__));
	if (stock_xpm(data) == 1)
		return (ft_dprintf(2, "Error: Invalid texture path in %s line %d\n",
				__FILE__, __LINE__));
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "prout");
	if (!data->win)
		return (ft_dprintf(2, "Error: mlx_new_window failed in %s line %d\n",
				__FILE__, __LINE__));
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img->img)
		return (ft_dprintf(2, "Error: mlx_new_image failed in %s line %d\n",
				__FILE__, __LINE__));
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->line_length, &data->img->endian);
	if (!data->img->addr)
		return (ft_dprintf(2, "Error: mlx_get_data_addr failed in %s line %d\n",
				__FILE__, __LINE__));
	return (0);
}
