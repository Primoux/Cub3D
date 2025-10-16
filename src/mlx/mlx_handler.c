#include "cub3d.h"
#include "mlx_management.h"

void	winner(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, handle_press_key, data);
	mlx_hook(data->win, 3, 1L << 1, handle_release_key, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, &move_player, data);
	mlx_loop(data->mlx);
}
