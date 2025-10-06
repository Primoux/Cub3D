#include "cub3d.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->floor);
	mlx_destroy_image(data->mlx, data->img->wall);
	mlx_destroy_image(data->mlx, data->img->perso);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_all(data);
	exit(0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	return (0);
}

// void	hooks(t_data data)