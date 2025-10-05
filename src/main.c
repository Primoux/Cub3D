#include "cub3d.h"
#include "mlx.h"
#include "parsing.h"
#include <X11/keysym.h>

void	winner(t_data data)
{
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WEIGHT, HEIGHT, "prout");
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Bad usage", 2);
		return (2);
	}
	init(&data);
	parsing(&data, &argv[1]);
	winner(data);
}
