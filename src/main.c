#include "cub3d.h"
#include "mlx.h"
#include <X11/keysym.h>

void	winner(t_data data)
{
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WEIGHT, HEIGHT, "prout");
	mlx_loop(data.mlx);
}

int	main(void)
{
	t_data	data;

	init(&data);
	winner(data);
	printf("coucou\n");
}
