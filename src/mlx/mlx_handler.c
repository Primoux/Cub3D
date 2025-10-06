#include "cub3d.h"
#include "mlx_management.h"

void	winner(t_data data)
{
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WEIGHT, HEIGHT, "prout");
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
	imaginer(data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}
